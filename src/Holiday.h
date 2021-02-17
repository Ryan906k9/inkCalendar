#ifndef _HOLIDAY_H
#define _HOLIDAY_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <string>
/**
 * Get ip information from api.xlongwei.com.
 * 
 * 
 */

/**
 * @brief Response from api.xlongwei.com query
 * 
 */
struct HolidayAPIResponse
{
    /**
     * @brief "2021"
     * 
     */
    String year;
    /**
     * @brief "春节"
     * 
     */
    String holiday;
    /**
     * @brief "2月11日至2月17日"
     * 
     */
    String remark;
    
    /**
     * @brief 提示信息
     * 
     */
    String message;

    
};

HolidayAPIResponse GetHolidayInfomation(void);


#endif