#include <iostream>
typedef long long LL;
using namespace std;
const int N = 1010;

int n,m;
int f[N];// ��ȡҩ������Ϊ N ʱ�������ֵ
int lo[N], w[N], v[N]; // ʧ�ܻ�õľ���ֵ���ɹ���õľ���ֵ��Ҫ���ĵ�ҩ������ 

int main()
{
    cin >> n >> m; // n------��������m-----ҩ����
    for (int i = 1; i <= n; i ++)
        cin >> lo[i] >> w[i] >> v[i];
    for (int i = 1; i <= n; i ++) // �������к���,�������
    // ���ڱ��������У��ڶԸ�ҩ��������������з���ʱ���� f[j - v[i]] �������õ�֮ǰ�ı䣬���Ա���Ӻ���ǰ����
        for (int j = m; j >= 0; j --) // ��������ҩ�������µ������ֵ
            if (j >= v[i])
                f[j] = max(f[j - v[i]] + w[i], f[j] + lo[i]);
            else f[j] += lo[i];
    cout << (LL)f[m]*5 ;
    return 0;
}