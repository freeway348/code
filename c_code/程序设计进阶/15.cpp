#include<bits/stdc++.h>
using namespace std;
const int maxx= 100+20;

int l;
int change(int shu){//���С���λ���ڱ߽�֮�⣬���Գƴ���ģ����ײ
    while(shu< 0||shu> l){
        while(shu< 0){
            shu= -shu;
        }
        while(shu> l){
            shu= 2*l- shu;
        }
    } 
    return shu;
}
int main(){

    int n, t;
    cin>>n>>l>>t;

    int vec[maxx];
    vector<int> pos(maxx, 0); 
    memset(vec, 0, sizeof(vec));
    for(int i= 0; i< n;i++)
     cin>>vec[i];



     for(int i= 0; i< n; i++){//��¼��0��n�����ֱ���n�����еĴ�
      //��С�ŵڼ�
         int count= 0;
        for(int j= 0; j< n; j++){
            if(vec[i]> vec[j])
             count++;
         }
         pos[i]= count;
     }

     for(int i= 0; i< n; i++){

        vec[i]= change(vec[i]+ t);//�ȿ���ֱ���˶�
     }

     sort(vec, vec+n);
     for(int  i= 0; i< n; i++){
        cout<<vec[pos[i]]<<' ';//��Ӧ�����Ӧ��λ����
     }
     cout<<endl;
    return 0;
}


