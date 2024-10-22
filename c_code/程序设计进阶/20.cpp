#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[n],sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum1+=a[i];
		if(sum1>=k){
			sum2++;
			sum1=0;
		}
		if(sum1>0&&sum1<k&&i==n-1){
			sum2++;
		}
	}
	cout<<sum2;
}

