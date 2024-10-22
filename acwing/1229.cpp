#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,int> PII;
vector<PII> p;//存储月 日

const int months[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int is_leap(int year)//判断闰年
{
    if (year %100 != 0 && year % 4 == 0 || year % 400 == 0)
        return 1;
    return 0;
}

int get_months_days(int year,int month)
{
    int res = 0;
    res += months[month];
    if (month == 2) res += is_leap(year);
    return res;
}

bool is_legal_date(int y, int m, int d)
{
    if (m > 12 || m < 1) return false;
    else 
    {
        if (d > get_months_days(y,m) || d <= 0) return false;
    }
    return true;
}

int main()
{
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    for (int i = 19600101; i <= 20591231; i ++)//遍历整个时间段
    {
        int year = i/10000,month = i / 100 % 100,day = i % 100;
        if (is_legal_date(year,month,day))//判断是否是合法的日期
        {
            //判断是否满足三种日期格式
            if (year % 100 == a && month == b && day == c || year % 100 == c && month == b && day == a || year % 100 == c && month == a && day == b)
            printf("%04d-%02d-%02d\n",year,month,day);
        }   
    }
    return 0;
}