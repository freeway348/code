#include<stdio.h>//运用C语言自带的qsort函数
#include<stdlib.h>
struct T{
    int yuzhi,n0,n1,count;
}t[1000001];
struct S{
    int x,y;
}s[100001];
int comp(const void* a,const void* b)
{
    struct S *aa = (struct S *)a;
    struct S *bb = (struct S *)b;
    return ((aa->x)-(bb->x)); 
}
int main()
{
	int m,i,j,x=0,temp=0,max=0;
    scanf("%d",&m);
    for(i=0;i<m;i++) {
      scanf("%d%d",&s[i].x,&s[i].y);
      t[i].n1=t[i].n0=t[i].count=t[i].yuzhi=0;
    }
    qsort(s,m,sizeof(s[0]),comp);
    t[0].yuzhi=s[0].x;
    if(s[0].y==0) t[0].n0++;
    else t[0].n1++;
    for(i=1,j=0;i<m;i++){
        if(s[i].x!=s[i-1].x) j++;
        t[j].yuzhi=s[i].x;
        if(s[i].y==0) t[j].n0++;
        else t[j].n1++;
    }
    for(i=0,temp=0;i<=j;i++){
        t[i].count+=temp;
        temp+=t[i].n0;
    }
    for(i=j,temp=0;i>=0;i--)
    {
        temp+=t[i].n1;
        t[i].count+=temp;
    }
     for(i=0;i<=j;i++)
    {
        if(t[i].count>max) {max=t[i].count;x=t[i].yuzhi;}
        else if(t[i].count==max) x=t[i].yuzhi;
    }
    printf("%d",x);
    return 0;
}


