//����һ����do������while ѭ�� 
#include <stdio.h>

#define N 100000

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    
    int x = q[(l + r)/2], i = l - 1, j = r + 1;
    
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j)
        {
            int t = q[i];
            q[i] = q[j];
            q[j] = t;
        }
    }
    //����ȡ i ʱһ������ȡ����߽磬���� x ��ȡֵҪΪ q[r] ���� q[(l + r + 1) / 2]
    //����ȡ j ʱһ������ȡ���ұ߽磬���� x ��ȡֵҪΪ q[l] ���� q[(l + r) / 2]
    //����������߽����⣬������ѭ��
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
    //��д��
    //quick_sort(q, l, i - 1);
    //quick_sort(q, i, r);
}

int main()
{
    int n,q[N];
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&q[i]);
    
    quick_sort(q, 0, n-1);
    
    for(int i = 0; i < n; i++) printf("%d ",q[i]);
    
    return 0;
}

//����������whileѭ������Ҫע��while��i < j���е�ѭ�����⣬��Ҫ��ѭ�� 
//#include <iostream>
//using namespace std;
//int n,p[100010];
//void quick_sort(int p[],int l, int r)
//{
//    if (l >= r) return;
//    int i = l,j = r, x = p[(l + r)/2];
//    while (i < j)//�����ڴ� 
//    {
//        while (p[i] < x) i++;
//        while (p[j] > x) j--;
//        if (i < j)
//        {
//        	swap(p[i],p[j]);
//        	i ++;
//        	j --;
//			     
//		}
//    }
//    quick_sort(p,l,j);
//    quick_sort(p,j+1,r);
//}
////1 3 2 5 4   x=p[2]=2;
////  i j
////1 2 3 5 4
////  i j     x = 2;
////���Ի���ѭ���� 
//int main()
//{
//    
//    scanf("%d",&n);
//    for (int i = 0; i < n; i++)
//        scanf("%d",&p[i]);
//    quick_sort(p,0,n-1);
//    for (int i = 0; i < n; i++)
//        printf("%d ",p[i]);
//    return 0;
////30
////128 294 133 295 175 8 232 248 241 164 11 60
////238 133 291 116 6 67 98 67 196 260 181 160
////83 160 90 153 233 216
//} 
