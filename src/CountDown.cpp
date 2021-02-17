#include "CountDown.h"

int DaysLeft(void)
{
    time_t rawtime, targettime;
    struct tm * targetTimeinfo, * todayTimeinfo;
    long daysLeft;

    // 获取当前信息
    time ( &rawtime );
    todayTimeinfo = localtime ( &rawtime );

    /* 获取当前时间信息，并修为倒计时的目标，即明年第一天 */
    time ( &targettime );
    targetTimeinfo = localtime ( &targettime );
    targetTimeinfo->tm_year = targetTimeinfo->tm_year + 1;
    targetTimeinfo->tm_mon = 0;
    targetTimeinfo->tm_mday = 1;
 
    /* 转换为 time_t 格式 */
    targettime = mktime ( targetTimeinfo );

    daysLeft =  (targettime - rawtime) / 3600 / 24 - 1;
 
    return daysLeft;
}

double PercentLeft(void)
{
    time_t rawtime;
    struct tm *targetTimeinfo;
    long future, last, today;
    double percent;

    time ( &rawtime );
    targetTimeinfo = localtime ( &rawtime );

    today = rawtime;

    /* 获取当前时间信息，并修为倒计时的目标，即明年第一天 */
    targetTimeinfo->tm_year = targetTimeinfo->tm_year + 1;
    targetTimeinfo->tm_mon = 0;
    targetTimeinfo->tm_mday = 1;

    future = mktime ( targetTimeinfo );

    /* 获取当前时间信息，并修为倒计时的目标，即明年第一天 */
    targetTimeinfo->tm_year = targetTimeinfo->tm_year - 1;
    targetTimeinfo->tm_mon = 0;
    targetTimeinfo->tm_mday = 1;

    last = mktime ( targetTimeinfo );

    percent = (double)( future - today ) / (double)( future - last );

    return percent;
}