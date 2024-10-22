// ˼·�ο�����������е� nlogn �Ż��������ɢ��˼·
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;
int n;
int a[N], b[N], q[N]; // q �������ɢ����� b ���������������е�ֵ
int alls[N]; // alls[i]:�洢ֵ i �ڵ�һ���е�λ�� 

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        alls[a[i]] = i;
    }
    for (int i = 0; i < n; i ++)
        cin >> b[i];

    int len = 0; // ����������еĳ���

    for (int i = 0; i < n; i ++) // �����ڶ���(����b)������ֵ
    {
        int l = 0, r = len;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < alls[b[i]]) // �ҵ����� q �е�С�� alls[b[i]] ������±�ֵ
                l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);

        q[r + 1] = alls[b[i]];
    }
    cout << len << endl;
    return 0;
}