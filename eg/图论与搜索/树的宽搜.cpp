// �⣺acwing 874.ͼ�е�Ĳ��
// ���� n ���㣬m ���ߣ��п��ܴ����رߺ��Ի������б߳���Ϊ 1 �����Ϊ 1 ~ n����� 1 �ŵ� n �ŵ����̾��룬����� 1 �߲��� n������� -1
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M = 2 * N;
int h[N],e[M], ne[M], idx;
int n,m;
int d[N],q[N]; // d ��¼���� 1 �ŵ㵽�õ�ľ��룬 q �Ƕ����д洢�ĵ�


void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = 1; 
    memset(d, -1, sizeof d);
    d[1] = 0; 
    while(hh <= tt)
    {
        int t = q[hh ++];

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }
    return d[n];
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
    }

    cout << bfs() << endl;

    return 0;
}