// Kruskal�㷨����С������

/* ��Ŀ��

����һ�� n ���� m ���ߵ�����ͼ��ͼ�п��ܴ����رߺ��Ի�����Ȩ����Ϊ������

����С������������Ȩ��֮�ͣ������С����������������� impossible��

����һ�űߴ�Ȩ������ͼ G=(V,E)������ V ��ʾͼ�е�ļ��ϣ�E ��ʾͼ�бߵļ��ϣ�
n=|V|��m=|E|��

�� V �е�ȫ�� n ������� E �� n?1 ���߹��ɵ�������ͨ��ͼ����Ϊ G ��һ�������������бߵ�Ȩֵ֮����С������������Ϊ����ͼ G ����С��������

�����ʽ
��һ�а����������� n �� m��

������ m �У�ÿ�а����������� u,v,w����ʾ�� u �͵� v ֮�����һ��ȨֵΪ w �ıߡ�

�����ʽ
��һ�У���������С�������������һ����������ʾ��С������������Ȩ��֮�ͣ�
�����С����������������� impossible��

���ݷ�Χ
1��n��10^5,1��m��2?10^5,ͼ���漰�ߵı�Ȩ�ľ���ֵ�������� 1000��

����������
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
���������
6

*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e6 + 10;
int n,m;
int p[N]; // ���鼯����

struct Edge
{
    int a,b,w;
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}edges[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }

    sort(edges, edges + m); // ��Ȩ�ش�С��������

    for (int i = 1; i <= n; i ++) p[i] = i; // ��ʼ�����鼯����

    int res = 0, cnt = 0; // res �������С��������Ȩֵ��cnt����Ǳ���

    for (int i = 0; i < m; i ++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        
        a = find(a), b = find(b); // �ҵ����ڽڵ�
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt ++;
        }
    }

    if (cnt < n - 1) cout << "impossible" << endl; // ��������еı����� n - 1 ������˵����Щ��û�õ������޷�������С������
    else cout << res << endl;
    return 0;
}