// // ��1:����ÿһ�е�ÿһ��,Ч�ʸ���
// #include <iostream>

// using namespace std;

// const int N = 20;
// int n; // �� n �� n �������ξ��� 
// char g[N][N]; // �������ϵĻʺ��Լ���λ
// bool col[N], dg[N],udg[N]; //�У��Խ��ߣ����Խ��� 

// void dfs(int u)
// {
//     if (u == n) // ��� 0 ~ n - 1 �㶼�Ѿ�����ˣ����˳�
//     {
//         for (int i = 0; i < n; i ++) cout << g[i] << endl;
//         cout << endl;
//         return ;
//     }
//     for (int i = 0; i < n; i ++) // ����ÿһ��
//     {
//         if (!col[i] && !dg[u + i] && !udg[n + i - u])
//         {
//             g[u][i] = 'Q';
//             col[i] = dg[u + i] = udg[n + i - u] = true;
//             dfs(u + 1);
//             g[u][i] = '.';
//             col[i] = dg[u + i] = udg[n + i - u] = false;
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i ++)
//         for (int j = 0; j < n; j ++)
//             g[i][j] = '.';
//     dfs(0); // �ӵ� 0 �п�ʼö��ÿһ��

//     return 0;
// }


// ��2������ÿһ�����ӣ�Ȼ��ѡ��Ż򲻷�
#include <iostream>

using namespace std;

const int N = 20;
int n; // �� n �� n �������ξ��� 
char g[N][N]; // �������ϵĻʺ��Լ���λ
bool row[N],col[N], dg[N],udg[N]; //�У��Խ��ߣ����Խ��� 

void dfs(int x, int y, int s) // x -------- �У� y --------- �У� s ------- �ѷŻʺ����
{
    if (y == n) 
    {
        y = 0; 
        x ++;
    }
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i ++) cout << g[i] << endl;
            cout << endl;
        }
        return ;
    }

    // ���Żʺ�
    dfs(x,y + 1,s);

    // �Żʺ�
    if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = true;
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = false;
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';
    dfs(0,0,0); // �ӵ� 0 �п�ʼö��ÿһ��

    return 0;
}
