#include<iostream>
using namespace std;

const int N = 1010;

int n, m;
int f[N][N], v[N], w[N];
// f[i][j]����ǰi����Ʒ��һ��j�ı��������������õ�������ֵ

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
        cin >> v[i] >> w[i];
        
    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j <= m; j ++ )
            for(int k = 0; k * v[i] <= j; k ++ ) 
	//һ������ѡk������0����ʼѡ��ֱ��ѡ��k�����Ƚ�����ȡֵ��fֵ�������������
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
                //���ÿһ�� f[i][j]
    cout << f[n][m] << endl;
    return 0;
}
