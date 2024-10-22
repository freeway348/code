#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 1010, M = 1e6 + 10;
int q[N][N], w[N], ans[N];
LL res;
bool st[N]; // st[i] : �� i ��ҩ�Ƿ��ҵ���ͻ���
int n;

int main()
{
    memset(q, -1, sizeof q);
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> w[i];
        ans[i] = 1;
    }
    int a,b,c;
    while(scanf("%d%d%d",&a, &b, &c) != EOF)
    {
        q[a][b] = c;
        q[b][a] = c; // a + b = c
    }
    for (int i = 0; i < n; i ++) // n ��ѭ�����ҵ�����ҩ����Сֵ
    {
        int vmin = 0x3f3f3f3f;
        for (int j = 0; j < n; j ++)
            if (!st[j] && w[j] < vmin) // ����� j ��ҩδ�ҵ���С����,���ҵ�������С��ҩ
            {
                vmin = w[j];
                b = j;
            }
        st[b] = true;
        // ��Ϊ������ A + A = B �������������ǰ���β��ҿ����Ҳ�����С���ѵ�ҩ����������������С���ѵ�ҩ�����ܺϳɵ�����ҩ
        // ����֮���·��� for ѭ���е� if (st-----) �жϵ�ǰ�������ǣ� �Ѿ��ҵ������еײ�ϼ����޷�������ҩ���ϳɵõ���ֻ�ܹ����ã�
        for (int j = 0; j < n; j ++) // �ҵ��õ�ҩ b ����С����
        {
            if (st[j] && q[b][j] != -1) // ����֪��С���ѵ�ҩ��ѡ��,���ҿ��Ժϳɵ�����ҩ
            {
                if (w[q[b][j]] == w[b] + w[j])// ���ֵ��ȣ����һЩ����
                    ans[q[b][j]] += ans[b] * ans[j];
                else if (w[b] + w[j] < w[q[b][j]])
                {
                    ans[q[b][j]] = ans[b] * ans[j];
                    w[q[b][j]] = w[b] + w[j];
                }
            }
        }        
    }
    cout << w[0] << ' ' << ans[0];
    return 0;
}