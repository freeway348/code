#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=1010;
int n,k,End=-2147483647,key[maxx],last[maxx];
struct node
{
	int w;//ʹ�õ�Կ�ױ�� 
	int s;//�Ͽο�ʼʱ�� 
	int c;//�Ͽ�ʱ�� 
	int end;//�Ͽν���ʱ�� 
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
		End=max(End,a[i].end);//End������Ļ�Կ��ʱ�� 
	}
	for(int i=1;i<=n;i++)
	key[i]=i,last[i]=i;
	for(int i=1;i<=End;i++)//�������⣬��Կ�׵�ѭ��������Կ�׵�ѭ��֮ǰ 
	{
		sort(a+1,a+k+1,cmd);//������ϰ��sort�������ڽṹ���ϵ�Ӧ�� 
		for(int j=1;j<=k;j++)//��Կ�� 
		if(a[j].end==i)
		  for(int l=1;l<=n;l++)
		  if(!key[l])
		  {
				key[l]=a[j].w;
				last[a[j].w]=l;
				break;
		  }
		for(int j=1;j<=k;j++)//��Կ�� 
		if(a[j].s==i)
		key[last[a[j].w]]=0;
	}
	for(int i=1;i<=n;i++)
	cout<<key[i]<<" ";
	return 0;
}
