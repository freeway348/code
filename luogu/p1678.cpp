#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int w[N];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> w[i];
    sort(w,w + n);
    LL res = 0;
    while(m --)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if (w[mid] > x) r = mid;
            else l = mid + 1;
        }
        if (x < w[0]) res += w[0] - x;//���У�����ѧ���ɼ�ȫ��ʱ����һ��ѧУ �������,��Ϊ��ʱ��ȡ����һλ w[0],�������� w[-1]�Ƚϣ������ڽ���һ��w[0]�����Աض��� 0 ����ʱ��min�ͻ����
        else res += min(abs(w[l] - x), abs(w[l - 1] - x));
    }
    cout << w[-1] << endl;
    cout << res;
    return 0;
}