#include "Huangli.h"

String TodayDate(void)
{
    time_t rawtime;
    struct tm * todayTimeinfo;
    String today;
    char buffer[15];

    // 获取当前信息
    time ( &rawtime );
    todayTimeinfo = localtime ( &rawtime );

    /* 转化为字符串 */
    sprintf(buffer, "%d-%d-%d", todayTimeinfo->tm_year + 1900, todayTimeinfo->tm_mon + 1, todayTimeinfo->tm_mday);
    today = buffer;

    Serial.println(todayTimeinfo->tm_year);
    Serial.println(todayTimeinfo->tm_mon);
    Serial.println(todayTimeinfo->tm_mday);
 
    return today;
}

HuangliAPIResponse GetHuangliInfomation(void)
{
    WiFiClient client;
    HTTPClient httpClient;
    HuangliAPIResponse response;

    String requestUrl = "http://api.tianapi.com/txapi/lunar/index?key=";
    requestUrl += HUANGLI_API_KEY;
    requestUrl += "&date=";
    DateTime.setTimeZone(8);
    DateTime.begin(/* timeout param */);
    requestUrl += DateTime.format(DateFormatter::DATE_ONLY).c_str();

    Serial.println(requestUrl);

    if(httpClient.begin(client,requestUrl))
    {
        u8_t httpCode = httpClient.GET();
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
        {
            String payload = httpClient.getString();
            Serial.println(payload);
            StaticJsonDocument<2048> doc;
            DeserializationError error = deserializeJson(doc, payload);
            if (error) 
            {
                Serial.print(F("deserializeJson() failed: "));
                Serial.println(error.f_str());
                return response;
            }

            int code = doc["code"]; // 200
            const char* msg = doc["msg"]; // "success"

            JsonObject newslist_0 = doc["newslist"][0];
            response.lunar_festival = newslist_0["lunar_festival"].as<String>();
            response.festival = newslist_0["festival"].as<String>();
            response.jieqi = newslist_0["jieqi"].as<String>();
            
            Serial.println(msg);
            
        }
        else
        {
            Serial.println("Get Huangli failed1\r\n");
        }
        
    }
    else
    {
        Serial.println("Get Huangli failed2\r\n");
    }
    
    httpClient.end();
    client.stop();
    return response;
}
