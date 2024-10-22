#include <iostream>
#define MAXN 1001
using namespace std;
int main() {

	int N;
	int T = 0;
	int D = 0;
	int E = 0;
	int tree[MAXN] = {0};
	cin >> N;//获取输入数据
	for (int i = 0; i < N; i++) {
		int m;
		int n;
		cin >> m >> n;
		for (int j = 0; j < m-1; j++) {
			int t;
			cin >> t;
			if (t > 0) {
				//发生了掉落,标记tree[i]
				if (n > t) {
					tree[i] = 1;
				}
				n = t;
			}
			else{
				n += t;
			}
		}
		T += n;
	}
	
	for (int i = 0; i < N; i++) {
		if (tree[i] > 0) {
			D++;
			if (tree[(i + 1) % N] > 0 && tree[(i - 1 + N) % N] > 0)
				E++;
		}
	}

	cout << T << " " << D << " " << E << endl;

	return 0;
}
