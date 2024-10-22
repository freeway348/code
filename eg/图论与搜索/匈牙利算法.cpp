// �����ͼ�����ƥ������

/* ���⣺

    ��Ŀ��
����һ������ͼ��������벿���� n1 ���㣨���Ϊ 1 ~ n1 �����Ұ벿���� n2 ���㣨��� 1 ~ n2��������ͼ������ m ���ߡ�

���ݱ�֤����һ���ߵ������˵㶼��������ͬһ�����С�

�����������ͼ�����ƥ������

����ͼ��ƥ�䣺����һ������ͼ G, �� G ��һ����ͼ M �У� M �ı߼� {E} �е����������߶���������ͬһ�����㣬��� M ��һ��ƥ�䡣

����ͼ�����ƥ�䣺����ƥ���а�����������һ��ƥ�䱻��Ϊ����ͼ�����ƥ�䣬�������Ϊ���ƥ������ 


    ���룺
��һ�а����������� n1��n2 �� m
������ m �У�ÿ�а����������� u �� v ,��ʾ��벿�㼯�еĵ� u ���Ұ벿�㼯�еĵ� v ֮�����һ���ߡ�

    �����
���һ����������ʾ����ͼ�����ƥ������

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;
int n1,n2,m;
int idx,e[M],h[N],ne[M];
int match[N]; // match[i] : �洢���ǵ� i ������ƥ��Ķ���
bool st[N]; // st[i] : �� i �����Ƿ���ƥ��

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x) // ���� x ��n1 �����е��ˣ� ��Ӧ(��ƥ��)�������� ��n2 �е������ˣ�
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) // ���û�����ǹ�
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) // ��� n2 �е� j ����δƥ�䣬������ƥ��Ķ�Ӧ n1 �е���������ѡ��
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    
    memset(h, -1, sizeof h);

    while(m --)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }

    int res = 0; // ƥ����
    for (int i = 1; i <= n1; i ++)
    {
        memset(st,false,sizeof st); // n2 �����е��˾�ֻ����һ�飬�Ƿ��ǹ��� st ��������
        if (find(i)) res ++; // ��� n1 �����е� i �����ҵ����Ӧ�� n2 ����ƥ���� + 1
    }
    cout << res << endl;
    return 0;
}