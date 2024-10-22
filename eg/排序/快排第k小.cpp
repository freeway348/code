//#include <iostream>
//using namespace std;
//
//int k;
//
//void quick_sort(int p[],int l, int r)
//{
//    if (l >= r) return;
//    int i = l - 1, j = r + 1, x = p[k - 1];
//	while (i < j)
//	{
//		do i ++; while (p[i] < x);
//	    do j --; while (p[j] > x);
//	    if (i < j) swap(p[i],p[j]);
//	}
//    quick_sort(p,l,j);
//    quick_sort(p,j + 1,r);
//}
//
//int main()
//{
//    int n;
//    cin >> n >> k;
//    int p[100010];
//    for (int i = 0; i < n; i ++)
//        cin >> p[i];
//    quick_sort(p,0,n-1);
//    cout << p[k - 1];
//    return 0;
//}


#include <iostream>
using namespace std;

int n,k;
int p[100010];

int quick_sort(int l,int r,int k)
{
    if (l == r) return p[l];
    int i = i - 1,j = r + 1, x = p[(l + r)/2];
    while (i < j)
    {
        do i ++ ; while (p[i] < x);
        do j -- ; while (p[j] > x);
        if (i < j) swap(p[i],p[j]);
    }
    int sl = j - l + 1;
    if ( k <= sl ) return quick_sort(l,j,k);
    return quick_sort(j + 1,r,k - sl);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> p[i];
    cout << quick_sort(0,n - 1,k);
    return 0;
}
