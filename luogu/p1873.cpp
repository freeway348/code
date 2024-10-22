#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int p[N];
int n;
LL m;

LL check(int x)//�õ������ܳ���
{
    LL res = 0;
    for (auto t : p)
        if (x < t) res += t - x;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> p[i];
    int l = 0, r = 4e5;
    while (l < r)   // ���յõ��� l �����ô��ڵ��� m �ĵ�һ�������ٵ� 1 ��Ҳ�ò��� m �׵�ľ���ˣ�
    {
        int mid = l + r + 1 >> 1;
        if (check(mid) >= m) l = mid; // ����õ�����ľ�ܳ��ȱ� m �������������������,���ӵȺ��жϻ����
        // ���жϲ��ӵȺţ���õ��� l - 1 ���������õ� m �׵�ľ��ʱ����߸߶ȣ��������Ҫ������Ҫ��߶���Υ��
        else r = mid - 1;
    }    
    cout << l ;
    return 0;
}