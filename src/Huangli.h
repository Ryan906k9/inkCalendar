#ifndef _HUANGLI_H
#define _HUANGLI_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <ESPDateTime.h>

const String HUANGLI_API_KEY = "############################";
/**
 * Get information from http://api.tianapi.com/txapi/lunar/index
 * 免费 API，每天可以 100 次调用
 * 
 * 
 * {
"code":200,
"msg":"success",
"newslist":[
{
"gregoriandate":"2019-01-13",
"lunardate":"2018-12-8",
"lunar_festival":"腊八节",
"festival":"",
"fitness":"祭祀.求财.签约.嫁娶.订盟",
"taboo":"开市.安床.安葬.入宅.破土",
"shenwei":"喜神：西北福神：西南财神：正东阳贵：东北阴贵：西南",
"taishen":"碓磨莫移动,鸡栖,床栖胎神在外东北停留6天",
"chongsha":"狗日冲(甲辰)龙",
"suisha":"岁煞北",
"wuxingjiazi":"木",
"wuxingnayear":"平地木",
"wuxingnamonth":"海中金",
"xingsu":"南方星日马-凶",
"pengzu":"庚不经络戌不吃犬",
"jianshen":"收",
"tiangandizhiyear":"戊戌",
"tiangandizhimonth":"乙丑",
"tiangandizhiday":"庚戌",
"lmonthname":"季冬",
"shengxiao":"狗",
"lubarmonth":"腊月",
"lunarday":"初八",
"jieqi":""
}
]
}
 */

/**
 * @brief Response from api.xlongwei.com query
 * 
 */
struct HuangliAPIResponse
{
    /**
     * @brief "农历2021年1月4日"
     * 
     */
    String nongli;
    String gregoriandate; // "2019-01-13",
    String lunardate; // "2018-12-8",
    String lunar_festival; // "腊八节",
    String festival; // "",
    String fitness; // "祭祀.求财.签约.嫁娶.订盟",
    String taboo; // "开市.安床.安葬.入宅.破土",
    String shenwei; // "喜神：西北福神：西南财神：正东阳贵：东北阴贵：西南",
    String taishen; // 碓磨莫移动,鸡栖,床栖胎神在外东北停留6天",
    String chongsha; // 狗日冲(甲辰)龙",
    String suisha; // "岁煞北",
    String wuxingjiazi; // "木",
    String wuxingnayear; // "平地木",
    String wuxingnamonth; // "海中金",
    String xingsu; // "南方星日马-凶",
    String pengzu; // "庚不经络戌不吃犬",
    String jianshen; // "收",
    String tiangandizhiyear; // "戊戌",
    String tiangandizhimonth; // "乙丑",
    String tiangandizhiday; // "庚戌",
    String lmonthname; // "季冬",
    String shengxiao; // "狗",
    String lubarmonth; // "腊月",
    String lunarday; // "初八",
    String jieqi; //""

    
};

HuangliAPIResponse GetHuangliInfomation(void);

#endif