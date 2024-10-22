#include <bits/stdc++.h>
using namespace std;

vector<int> add (vector<int> a,vector<int> b)
{
	if (a.size() < b.size()) return add(b,a);
	vector<int> c;
	int t= 0;
	for (int i = 0; i < a.size(); i++)
	{
		t += a[i];
		if (i < b.size()) t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if (t) c.push_back(t);
	return c;
}

int main()
{
	string A,B;
	vector<int> a,b,c;
	cin >> A >> B;
	for (int i = A.size() - 1; i >= 0; i--)
		a.push_back(A[i] - '0');
	for (int i = B.size() - 1; i >= 0; i--)
		b.push_back(B[i] - '0');	
	c = add(a,b);
	for (int i = c.size() -1; i >= 0; i--)
		cout << c[i];
}

