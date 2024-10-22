#include <iostream>
#include <queue>
typedef long long LL;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> heap;
	for (int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		heap.push(x);//将x加到小根堆的堆顶,建立起来的数据存储与哈夫曼树是反过来的
	}
	LL res = 0;
	while(heap.size() > 1)
	{
		int a = heap.top(); heap.pop();
		int b = heap.top(); heap.pop();
		res += a + b;
		heap.push(a + b);
	}
	cout << res;
	return 0;
}
