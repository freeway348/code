//归并排序 ----------- 分治
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
int p[N],temp[N];//temp数组用于存储两个区间合并后的有序数

void merge_sort(int q[],int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j]) temp[k++] = q[i++];
        else temp[k ++ ] = q[j ++];
    }
    while (i <= mid) temp[k++] = q[i++];
    while (j <= r ) temp[k ++] = q[j ++];
    for (int i = l, j = 0;i <= r; i ++, j ++) q[i] = temp[j];//把temp数组里的数重新存回原数组 q 中
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> p[i];
    merge_sort(p,0, n - 1);
    for (int i = 0; i < n; i ++)
        cout << p[i] << ' ';
    return 0;
}