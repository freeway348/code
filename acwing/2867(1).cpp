//y总板子
//check函数可记，作为日期问题板子
#include <iostream>

using namespace std;

const int months[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool check_poli(int date)//判断日期是否合法
{
    int y = date / 10000, m = date / 100 % 100, d = date % 100;//或者写成month = date % 10000 / 100;
    if (!m || m > 12 || !d) return false;
    if (m != 2 && d > months[m]) return false;
    if (m == 2)
    {
        bool leap = y % 100 && y % 4 == 0 || y % 400 == 0;//c++中true为1，false为0
        if (d > leap + months[m]) return false;
    }

    return true;
}

int main()
{
    int date, cnt = 0;
    cin >> date;
    for (int i = date / 10000; i <= 9999; i ++)//因为是判断回文，所以只取一半即可
    {
        int r = i, x = i;//r为左半边，x为右半边，将右半边从右到左添加到左半边后，最终判断20200202是否为合法日期即可
        for (int j = 0; j < 4; j ++)
        {
            r = r * 10 + x % 10;//将x的最小位加到r的最小位上
            x /= 10;//去掉最小位的数
        }
        if (check_poli(r) && !cnt && r > date) cnt ++,cout << r << '\n';
        if (check_poli(r) && i / 100 == i % 100 && i % 10 != i / 1000 && cnt)//要考虑A!=B
        {
            cout << r;
            break;
        }
    }
    
    return 0;
}