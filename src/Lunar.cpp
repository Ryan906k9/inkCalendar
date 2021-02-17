#include "Lunar.h"

LunarAPIResponse GetLunarInfomation(void)
{
    WiFiClient client;
    HTTPClient httpClient;

    LunarAPIResponse response;
    response.message = "fail";

    String requestUrl = "http://api.xlongwei.com/service/datetime/convert.json";
    Serial.println(requestUrl);

    if(httpClient.begin(client,requestUrl))
    {
        u8_t httpCode = httpClient.GET();
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
        {
            String payload = httpClient.getString();
            Serial.println(payload);
            StaticJsonDocument<1024> doc;
            deserializeJson(doc, payload);

            response.nongli = doc["nongli"].as<String>();
            response.chinese = doc["chinese"].as<String>();
            response.ganzhi = doc["ganzhi"].as<String>();
            response.shengxiao = doc["shengxiao"].as<String>();
            response.lunarYear = doc["lunarYear"].as<int32_t>();
            response.lunarMonth = doc["lunarMonth"].as<int32_t>();
            response.lunarDay = doc["lunarDay"].as<int32_t>();
            response.isLeapMonth = doc["isLeapMonth"].as<bool>();

            Serial.println(response.chinese);
            
        }
        else
        {
            Serial.println("Get Lunar failed1\r\n");
        }
        
    }
    else
    {
        response.message = "httpClient failed.";
        Serial.println("Get Lunar failed2\r\n");
    }
    
    httpClient.end();
    client.stop();
    return response;
}
