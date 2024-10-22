#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e6 + 10, M = 2e6 + 10;

int n,m;
char p[N],s[M];// p ---- ���ַ���; s --------- ���ַ���; ne----------- next ����
int ne[N];

int main()
{
    cin >> s + 1 >> p + 1;// �±�� 1 ��ʼ
    n = strlen(p + 1);
    m = strlen(s + 1);

    // ��next���飨ǰ׺�ͺ�׺��ƥ������
    for (int i = 2, j = 0; i <= n; i ++) // ���ַ�������Ϊ m,�� i ��ʼ��ƥ���ַ�������Ϊn���� j ��ʼ
    {
        while (j && p[i] != p[j + 1]) j = ne[j]; // ��� j û�˵���㣬����ǰ��׺��ƥ�䣬�� next ������˵� ne[j] ��λ��
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++)
    {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n) // ƥ��ɹ�
        {
            cout << i - n + 1 << endl; // ���ƥ��ɹ�ʱ�����ַ���ʼλ��
            j = ne[j]; // ������ s ������;��ƥ��ɹ��ˣ�����������Ҫ�����ҿ�����û������ƥ���ַ���������ʱ j �Ѿ��ߵ���β�ˣ�������Ҫ����һ��
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << ne[i] << ' ';

    return 0;
}