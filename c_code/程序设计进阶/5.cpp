#include<iostream>
#include<algorithm>
using namespace std;
int n,k,t,xl,yd,xr,yu;
int main()
{
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    int ans_pass = 0;//������Σ���������
    int ans_wait = 0;//������Σ���������
    while(n--)
    {
        int sum = 0;//������¼�����������
        int last = 0;//��¼�����������
        for(int i=1;i<=t;i++)
        {
            int x,y;
            cin>>x>>y;
            //�ڸ�Σ������
            if(x>=xl&&y>=yd&&x<=xr&&y<=yu)
            {
                sum++;
                last = max(sum,last);//ȡ��󳤶�
            }
            else
            {
                sum = 0;
            }
        }
        //����
        if(last>0)
        {
            ans_pass++;
        }
        //������
        if(last>=k)
        {
            ans_wait++;
        }
    }
    cout<<ans_pass<<endl<<ans_wait<<endl;
}

