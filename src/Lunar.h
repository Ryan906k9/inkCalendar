#ifndef _LUNAR_H
#define _LUNAR_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <string>
/**
 * Get information from api.xlongwei.com.
 * 
 * 
 */

/**
 * @brief Response from api.xlongwei.com query
 * 
 */
struct LunarAPIResponse
{
    /**
     * @brief "农历2021年1月4日"
     * 
     */
    String nongli;
    /**
     * @brief "二零二一年正月初四"
     * 
     */
    String chinese;
    /**
     * @brief "辛丑"
     * 
     */
    String ganzhi;
    /**
     * @brief "牛"
     * 
     */
    String shengxiao;
    /**
     * @brief 2021
     * 
     */
    String lunarYear;
    /**
     * @brief 1
     * 
     */
    String lunarMonth;
    /**
     * @brief 4
     * 
     */
    String lunarDay;
    /**
     * @brief false
     * 
     */
    bool isLeapMonth;
    /**
     * @brief 提示信息
     * 
     */
    String message;

    
};

LunarAPIResponse GetLunarInfomation(void);


#endif