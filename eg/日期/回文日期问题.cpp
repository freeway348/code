//y�ܰ���
//check�����ɼǣ���Ϊ�����������
//����20ms
#include <iostream>

using namespace std;

const int months[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool check(int date)//�ж������Ƿ�Ϸ�
{
    int y = date / 10000, m = date / 100 % 100, d = date % 100;//����д��month = date % 10000 / 100;
    if (!m || m > 12 || !d) return false;
    if (m != 2 && d > months[m]) return false;
    if (m == 2)
    {
        bool leap = y % 100 && y % 4 == 0 || y % 400 == 0;//c++��trueΪ1��falseΪ0
        if (d > leap + months[m]) return false;
    }

    return true;
}

int main()
{
    int date1,date2,res = 0;
    cin >> date1 >> date2;
    for (int i = 0; i <= 9999; i ++)//��Ϊ���жϻ��ģ�����ֻȡһ�뼴��
    {
        int r = i, x = i;//rΪ���ߣ�xΪ�Ұ�ߣ����Ұ�ߴ��ҵ�����ӵ����ߺ������ж��Ƿ�Ϊ�Ϸ����ڼ���
        for (int j = 0; j < 4; j ++)
        {
            r = r * 10 + x % 10;//��x����Сλ�ӵ�r����Сλ��
            x /= 10;//ȥ����Сλ����
        }
        if (r >= date1 && r <= date2 && check(r)) res ++;
    }
    cout << res;
    return 0;
}