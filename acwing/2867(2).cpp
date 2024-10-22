//y总代码
//820ms
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

int get_days(int y, int m)
{
    if (m == 2) return 28 + is_leap(y);
    return months[m];
}

void next_day(int& y, int& m, int& d)//计算下一天的日期,并同步改变y,m,d
{
    d ++;
    if (d > get_days(y,m))
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

bool check1 (char s[])
{
    for (int i = 0, j = 7; i < j; i ++, j --)
        if (s[i] != s[j])
            return false;
    return true;
}

bool check2 (char s[])
{
    char a = s[0], b = s[1], c = s[2], d = s[3];
    if (a == c && b == d && a != b)
        return true;
    return false;
}

int main()
{
    int y, m, d;
    scanf("%04d%02d%02d", &y, &m, &d);
    
    char s[10] = {0};

    bool found1 = false, found2 = false;

    while (!found1 || !found2)
    {
        next_day(y,m,d);
        sprintf(s,"%04d%02d%02d",y, m, d);// 将y,m,d打印到字符串s中
        if (check1(s))//如果满足回文要求
        {
            if (!found1)
            {
                puts(s);
                found1 = true;
            }
            if (!found2 && check2(s))
            {
                puts(s);
                found2 = true;
            }
        }
    }
    return 0;
}