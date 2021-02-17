#include "Holiday.h"

HolidayAPIResponse GetHolidayInfomation(void)
{
    WiFiClient client;
    HTTPClient httpClient;

    HolidayAPIResponse response;
    response.message = "fail";

    String requestUrl = "http://api.xlongwei.com/service/datetime/holiday.json";
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

            response.year = doc["year"].as<String>();
            response.holiday = doc["holiday"].as<String>();
            response.remark = doc["remark"].as<String>();

            Serial.println(response.holiday);
            
        }
        else
        {
            Serial.println("Get Holiday failed1\r\n");
        }
        
    }
    else
    {
        response.message = "httpClient failed.";
        Serial.println("Get Holiday failed2\r\n");
    }
    
    httpClient.end();
    client.stop();
    return response;
}
