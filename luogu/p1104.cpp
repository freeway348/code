#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

struct node
{
    string x;
    int y; // ����
    int z; // ����˳��
    bool operator< (const node & M)const
    {
        if (y == M.y) return z > M.z; // ������ͬ���򿿺�����������
        return y < M.y; // ����Ӵ�С,�����������ڴ�С����
    }
}p[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int a,b,c;
        string A;
        cin >> A >>  a >> b >> c;
        int t = c + b * 100 + a * 10000;
        p[i].x = A;
        p[i].y = t;
        p[i].z = i;
    }
    sort(p +  1, p + n + 1);
    for (int i = 1; i <= n; i ++)
        cout << p[i].x << endl;
    return 0;
}