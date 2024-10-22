//自作
//运行1700ms
//ps：测试数据量大，这样写容易tle，建议学习y总代码思路
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int months[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int is_leap(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)    
        return 1;
    return 0;
}

int get_months_day(int year,int month)
{
    int res = 0;
    res += months[month];
    if (month == 2) res += is_leap(year);
    return res;
}

void next_day(int& y, int& m, int& d)//计算下一天的日期,并同步改变y,m,d
{
    d ++;
    if (d > get_months_day(y,m))
    {
        d = 1;
        m ++;
    }
    if (m > 12)
    {
        m = 1;
        y ++;
    }
}

int main()
{
    int y,m = 1,d = 0,gap;
    cin >> y >> gap;
    for (int i = 1; i <= gap; i ++)
    {
        next_day(y,m,d);
    }
    cout << m << '\n' << d;
    return 0;
}