#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

const int N = 55;
int n,m;
char g[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0 , -1};
vector<pair<int,int>> points[2];

void dfs(int a, int b, vector<pair<int,int>>& q)
{
	q.push_back({a, b});
	//记得将填入vector数组q中的元素改为. 或使用st标记也可
	g[a][b] = '.';
	for (int i = 0; i < 4; i ++)
	{
		int x = dx[i] + a, y = dy[i] + b;
		if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 'X')
			dfs(x, y, q);
	}
 } 

int main(int argc, char** argv) {
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i ++) 
	    scanf("%s", g[i]);
		
	int k = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (g[i][j] == 'X')
				dfs(i, j, points[k ++]);
	int res = 110;//记录最短距离 
	for (auto& a : points[0])
		for (auto& b : points[1])
			res = min(res, abs(a.first - b.first) + abs(a.second - b.second));
	printf("%d\n",res - 1);
	return 0;
}
