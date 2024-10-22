#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=1010;
int n,k,End=-2147483647,key[maxx],last[maxx];
struct node
{
	int w;//使用的钥匙编号 
	int s;//上课开始时间 
	int c;//上课时长 
	int end;//上课结束时间 
}a[maxx];
int cmd(const node &a,const node &b)
{
	return a.w<b.w;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].w>>a[i].s>>a[i].c;
		a[i].end=a[i].s+a[i].c;
		End=max(End,a[i].end);//End是最晚的还钥匙时间 
	}
	for(int i=1;i<=n;i++)
	key[i]=i,last[i]=i;
	for(int i=1;i<=End;i++)//根据题意，还钥匙的循环放在拿钥匙的循环之前 
	{
		sort(a+1,a+k+1,cmd);//重新温习了sort排序函数在结构体上的应用 
		for(int j=1;j<=k;j++)//还钥匙 
		if(a[j].end==i)
		  for(int l=1;l<=n;l++)
		  if(!key[l])
		  {
				key[l]=a[j].w;
				last[a[j].w]=l;
				break;
		  }
		for(int j=1;j<=k;j++)//拿钥匙 
		if(a[j].s==i)
		key[last[a[j].w]]=0;
	}
	for(int i=1;i<=n;i++)
	cout<<key[i]<<" ";
	return 0;
}
