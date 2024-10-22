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

//快速幂
int Pow(int a, int b) //a为底数，b为幂级数
{
    int ans = 1, base = a;
    while (b) 
    {
        if (b & 1)//当b的二进制最低位为1时才进行
            ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}


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

bool is_legal_date(int year,int month, int day)
{

    if (month > 12 || month < 1) return false;
    else
    {
        if (day <= 0 || day > get_months_day(year,month)) return false;
    }
    return true;
}

bool is_pali(int date)
{
    int l, r;
    int k = 7;//日期一共有八位,这里存的是10的次方
    while (date)
    {
        l = date / Pow(10,k), r = date % 10;
        if (l != r) 
        {
            return false;
            break;
        }
        date %= Pow(10,k);
        date /= 10;//去掉最低位
        k -= 2;
    }
    return true;
}

int main()
{
    int date1,date2;
    cin >> date1 >> date2;
    int res = 0;
    for (int i = date1; i <= date2; i++)
    {
        int y = i / 10000, m = i / 100 % 100, d = i % 100;
        if (is_legal_date(y,m,d))
        {
            if (is_pali(i)) res ++;
        }
    }
    cout << res;
    return 0;
}