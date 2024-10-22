#include <iostream>
#include <algorithm>
using namespace std;

const int months[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int is_leap(int year)//判断闰年
{
    if (year %100 != 0 && year % 4 == 0 || year % 400 == 0)
        return 1;
    return 0;
}

int get_months_days(int year, int month)//计算最后一年第month个月的总天数
{
    int res = 0;
    res += months[month];
    if (month == 2) res += is_leap(year);
    return res;
}

int get_total_days(int year, int months, int days)
{
    int res = 0;
    for (int i = 1; i < year; i ++)//先计算从元年（0001年）到现在这年为止的总天数
        res += 365 + is_leap(i);
    for (int i = 1; i < months; i ++)//计算这一年每月的天数和
        res += get_months_days(year,i);
    res += days;//加上最后一个月的天数
    return res;
}


int main()
{
    int y1,m1,d1,y2,m2,d2;
    while (scanf("%04d%02d%02d",&y1,&m1,&d1) != -1)
    {
        scanf("%04d%02d%02d",&y2,&m2,&d2);
        cout << abs(get_total_days(y1,m1,d1) - get_total_days(y2,m2,d2)) + 1 << '\n';
    }
    return 0;
}