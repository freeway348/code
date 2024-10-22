#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int num;
	string ch;
	cin >> ch;
	num = 1*(ch[0]-48);
	for (int i=2;i<5;i++)
		num += i*(ch[i]-48);
	for (int i=6;i<11;i++)
		num += (i-1)*(ch[i]-48);
	if (num%11 != 10 && num%11 == ch[12]-48)
		cout << "Right" << endl;
	else if (num%11 == 10 && ch[12] == 'X')
		cout << "Right" << endl;
	else 
	{
		if (num%11 == 10)
		{
			ch[12] = 'X';
			cout << ch;
		}
		else if (num%11 != 10)
		{
			ch[12] = num%11 + 48;
			cout << ch;		
		}
	}
	return 0;
}
