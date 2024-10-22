#include<iostream>
#include<algorithm>
using namespace std;
int n,k,t,xl,yd,xr,yu;
int main()
{
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    int ans_pass = 0;//经过高危区域的人数
    int ans_wait = 0;//逗留高危区域的人数
    while(n--)
    {
        int sum = 0;//辅助记录最大连续长度
        int last = 0;//记录最大连续长度
        for(int i=1;i<=t;i++)
        {
            int x,y;
            cin>>x>>y;
            //在高危区域内
            if(x>=xl&&y>=yd&&x<=xr&&y<=yu)
            {
                sum++;
                last = max(sum,last);//取最大长度
            }
            else
            {
                sum = 0;
            }
        }
        //经过
        if(last>0)
        {
            ans_pass++;
        }
        //逗留过
        if(last>=k)
        {
            ans_wait++;
        }
    }
    cout<<ans_pass<<endl<<ans_wait<<endl;
}

