#include<iostream>
#include<vector>
using namespace std;
int operate(int a,char c,int b){
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='x') return a*b;
	if(c=='/') return a/b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		vector<int> num(4);
		int pos,rs=0;
		vector<char> op(3);
		for(int j=0;j<3;j++){
			scanf("%d",&num[j]);
			scanf("%c",&op[j]);
		}
		scanf("%d",&num[3]);
		for(int j=0;j<3;j++){
			for(pos=0;pos<op.size()&&op[pos]!='x'&&op[pos]!='/';pos++);
			if(pos==op.size()) pos=0;
			rs=operate(num[pos],op[pos],num[pos+1]);
			num[pos]=rs; 
			num.erase(num.begin()+pos+1);
			op.erase(op.begin()+pos);
		}
		printf(rs==24?"Yes\n":"No\n");
	}
	return 0;
}

