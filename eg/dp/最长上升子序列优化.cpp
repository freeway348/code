// ��������Ϊ 1e5�����ݷ�Χ�� -2e9 ~ 2e9 ֮�䣬����֮ǰ�� O(n^2) ���������������У���Ҫ�Ż�
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
int a[N], q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)    cin >> a[i];
    int len = 0; // ����������еĳ���
    q[0] = -2e9; // ����߽�����
    for (int i = 0; i < n; i ++)
    {
        int l = 0, r = len;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            // �ҵ���֪������������б� a[i] С�ġ� ����ֵ
            if (q[mid] < a[i]) 
                l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1); // �� a[i] �ӵ� q[r] ��ߣ����ֲ��Һ������� q[r + 1]���ض��� a[i] �����Կ����滻�����������ֵ���� a[i] С����ô�ͻὫ a[i] �ӵ��µ�һλ
        // ��Ϊ������������ʱ��С�����϶��ȴ�����������������У����磺1 3 4 �� 1 3 6 �����ҵ�����������������
        q[r + 1] = a[i]; // ����У��������û�о����
        
    }
    cout << len << endl;
    return 0;
}