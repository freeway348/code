#include<iostream>
#include<string>
using namespace std;
#define MAX 100+5

string strs[MAX];

void output(string str){		//输出转换
	for(int i = 0; i< str.length();i++){
		if(str[i] == '_'){
			int r = str.find('_', i+1);
			output("<em>" + str.substr(i + 1, r - i - 1) + "</em>");
			i = r;
		}

		else if(str[i] == '['){
			int r = str.find(']', i + 1);
			int ll = str.find('(', r + 1);
			int lr = str.find(' )', ll + 1);
			string Text = str.substr(i + 1, r - i - 1);
			string link = str.substr(ll + 1, lr - ll - 1);
			output("<a href=\""  + link + "\">" + Text + "</a>");
			i = lr;
		}
		else cout<<str[i];
	}
}


void output_h(){			//标题
	int level = 0;
	int pos = strs[0].length();
	for(int i = 0;i < strs[0].length();i++){
		if(strs[0][i] == '#') level++;
		else if(strs[0][i] != '#' && strs[0][i] != ' ') {
			pos = i;
			break;
		}
	}
	cout<<"<h"<<level<<">";
	output(strs[0].substr(pos));
	cout<<"</h"<<level<<">"<<endl;

}

void output_u(int cnt){			//列表
	cout<<"<ul>"<<endl;
	for(int i = 0; i < cnt; i++){
		int pos  = strs[i].length();
		for(int j = 1; j < strs[i].length(); j++ ){
			if(strs[i][j] != ' ') {
				pos = j;
				break;
			}
		}
		cout<<"<li>";
		output(strs[i].substr(pos));
		cout<<"</li>"<<endl;
	}
	cout<<"</ul>"<<endl;
}

void output_p(int cnt){			//段落
	cout<<"<p>";
	for(int i = 0; i < cnt; i++) {
		if(i == 0) output(strs[i]);
		else{
			cout<<endl;
			output(strs[i]);
		}
	}
	cout<<"</p>"<<endl;
}

int main(){
	int cnt = 0;
	string line;
	while(getline(cin, line)){
		if(line == ""){
			if(strs[0] == "") continue;
			if(strs[0][0] == '#')output_h();
			else if(strs[0][0] == '*')output_u(cnt);
			else output_p(cnt);
			cnt = 0;
			strs[0] = "";
		}
		else strs[cnt++] = line;
	}
	if(cnt){		//文件尾未必是回车，要判断是否读取完毕
		if(strs[0][0] == '#')output_h();
		else if(strs[0][0] == '*')output_u(cnt);
		else output_p(cnt);
	}
	return 0;
}

