/*
    �ⳡ�����У�����С��ʯ�ӵ����� >= 2, �� Alice ��ʤ����ΪAlice ����ѡ��ÿ��ȡ��С�ѵ�ʯ���� - 1���� Bobֻ��ȡ��һ��ʯ��
    ����С��ʯ��Ϊ 1�� 

*/ 
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        int p[200010] = {};
        cin >> n;
        int c = 1;
        for (int i = 1; i <= n; i ++)
            cin >> p[i];
        sort(p + 1, p + n + 1);

        // ����Ҫȥ�أ���Ϊÿ�β����Ƕ�����ʯ�Ӷѽ��еģ������ȥ�أ�����������ʴ���
        int end = unique(p + 1,p + n + 1) - p - 1; // ���ظ����е�Ԫ�ص�����
        for (int i = 1; i <= end; i ++)
        {
            if (p[i] == c)
                c ++;
        }

        
        if (p[n] < c) // ���ʯ�Ӷ��Ǵ� 1 ��ʼ������ + 1 �����У��磺 1 2 3 4 5 6 7 8 9
            if (p[n] % 2 == 1) // ƾ��ż���ж�ʤ��-----------��Ϊÿ����ÿ�ζ�ֻ���� 1 ��
                cout << "Alice" << endl;
            else 
                cout << "Bob" << endl;
        else // ���ǰ���ξ�ֻ���� 1 �������ӵ� i �ο�ʼ����Сʯ�Ӷѵ�ʯ���� >= 2�����ʱ�����ּ�Ϊ��ʤ̬
        {
            if (c % 2 == 1)
                cout << "Alice" << endl;
            else 
                cout << "Bob" << endl;
        }
    }
    return 0;
}