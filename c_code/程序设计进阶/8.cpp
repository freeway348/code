#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int KMAX =  1e2 + 10;
const int SIZEMAX = 5e4 + 10;
const long long INF = 0x3f3f3f3f3f;

class Pair
{
public:
	int side;
	int weight;
	Pair(int x, int y) : side(x), weight(y) {}
};


std::vector<Pair> SideSet[SIZEMAX];
int node[SIZEMAX];
long long assist[SIZEMAX];
long long dp[SIZEMAX][KMAX];
int judge[SIZEMAX];
int k;

void input(){
	int n, m;
	cin >> n >> m >> k;
	memset(dp, INF, sizeof(dp));
	for (int i = 1; i <= m; ++i)
	{
		int side;
		cin >> side;
		judge[side] = 1;
	}
	for (int i = 2; i <= n; ++i)
	{
		int side1, side2, weigth;
		cin >> side1 >> side2 >> weigth;
		SideSet[side1].push_back(Pair(side2, weigth));
		SideSet[side2].push_back(Pair(side1, weigth));
	}
}
void mark(int point)
{
	dp[point][0] = 0;
	if (judge[point] == 1)
	{
		node[point] = 1;
		dp[point][1] = 0;
	}
}

void find(int point, int father)
{
	mark(point);
	for (int i = 0; i < SideSet[point].size(); i++)
	{
		int son = SideSet[point][i].side, weight = SideSet[point][i].weight;
		if (son != father)
		{
			find(son, point);
			int num = node[point] + node[son] < k ? node[point] + node[son] : k;
			int tt = node[point] < k ? node[point] : k;
			for (int p = 0; p <= num; ++p){
				assist[p] = dp[point][p];
			}
			
			for (int p = 0; p <= tt; ++p){
				for (int q = 0; q <= num-p; ++q)
				{
					dp[point][p+q]=min(dp[point][p+q],assist[p]+dp[son][q]+q*(k-q)*weight);
				}
			}
			node[point] += node[son];	
		}
	}
}
int main()
{
	input();
	find(1, -1);
	cout << dp[1][k];
	return 0;
}

