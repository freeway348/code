//ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½doï¿½ï¿½ï¿½ï¿½ï¿½ï¿½while Ñ­ï¿½ï¿½ 
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
    //²ÎÊýÈ¡ i Ê±Ò»¶¨²»ÄÜÈ¡µ½×ó±ß½ç£¬ËùÒÔ x µÄÈ¡ÖµÒªÎª q[r] »òÕß q[(l + r + 1) / 2]
    //²ÎÊýÈ¡ j Ê±Ò»¶¨²»ÄÜÈ¡µ½ÓÒ±ß½ç£¬ËùÒÔ x µÄÈ¡ÖµÒªÎª q[l] »òÕß q[(l + r) / 2]
    //·ñÔò»áÓöµ½±ß½çÎÊÌâ£¬³öÏÖËÀÑ­»·
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
    //»òÐ´£º
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

//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½whileÑ­ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Òª×¢ï¿½ï¿½whileï¿½ï¿½i < jï¿½ï¿½ï¿½Ðµï¿½Ñ­ï¿½ï¿½ï¿½ï¿½ï¿½â£¬ï¿½ï¿½Òªï¿½ï¿½Ñ­ï¿½ï¿½ 
//#include <iostream>
//using namespace std;
//int n,p[100010];
//void quick_sort(int p[],int l, int r)
//{
//    if (l >= r) return;
//    int i = l,j = r, x = p[(l + r)/2];
//    while (i < j)//ï¿½ï¿½ï¿½ï¿½ï¿½Ú´ï¿½ 
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
////ï¿½ï¿½ï¿½Ô»ï¿½ï¿½ï¿½Ñ­ï¿½ï¿½ï¿½ï¿½ 
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
