// �⣺acwing�� ����ͼ����������
// �������� --------- ͼ�Ŀ��ѵ�Ӧ��
// ͼ����������------------����ͼ
// �����޻�ͼһ������ �������� �������ֱ���Ϊ����ͼ
// �� һ�������� ��������
// �����޻�ͼ�ض�����һ�����Ϊ 0 �ĵ�----------�������
// ���ʻ��ǿ���
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int h[N],e[N],ne[N],idx; 
int q[N],d[N]; // q ����洢�����������У�d ����洢�������
int n,m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool topsort() // ��Ϊ�������޻�ͼ�У����С�ĵ�϶��ڸ�ǰ�棬���� q �����д��Ҳ�Ƿ�����������Ҫ���������
{
    int hh = 0, tt = -1; 
    // tt ȡ -1 ����Ϊ������� 1 ~ n ��ֻ����һ�����Ϊ 0 ����㣬���ʱ q ���飨ģ����У��н���һ��Ԫ�أ����Ըպ÷��� hh <= tt ������
    // ����� 0 ��ʼ����ᵼ�� q ������ֻ��һ��Ԫ�أ�whileѭ��ȴҪ����ѭ������
    for (int i = 1; i <= n; i ++)
        if (!d[i]) // ������Ϊ 0
            q[++ tt] = i; // ��β���

    while (hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --; // ÿ�ҵ��õ��һ����ȣ���һ���㣩���ͽ������ - 1
            if (!d[j]) // ���������ȱ�Ϊ 0�� ��˵�����ǻ�
                q[++ tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        d[b] ++;
    }
    if (topsort())
    {
        for (int i = 0; i < n; i ++) cout << q[i] << ' ';
    }
    else cout << -1 << endl;
    return 0;
}
