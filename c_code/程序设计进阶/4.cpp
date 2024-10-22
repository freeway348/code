#include <iostream>
#include <vector>
#include <queue>  // queue
#include <string.h>  // memcpy ...
#include <algorithm>  // atoi、 fill

using namespace std;

// 常量
const int MAXK = 5;
const int MAXN = 501;
const int MAXM = 2501;  // k * N
const int MAXS = 100001;

// 器件
vector<int> tab[MAXN + MAXM]; // 邻接表（包含输入和器件） dce[i][j]: i->j
string type[MAXN];            // 每个器件的类型
int InD[MAXN + MAXM];         // 每个器件和输入的入度

// 输入
vector<vector<int> > input;     // 输入
vector<vector<int> > outputDev;  // 每个输入要求输出的器件编号

// 输出
int output[MAXN + MAXM];  // 输入和器件的结果


// 判断邻接表是不是有向无环图
bool topologicalSort(int  N, int M) {
    int curInD[MAXN + MAXM];
    memcpy(curInD, InD, sizeof(InD));

    queue<int> que;  // 记录入度为0
    for (int i = 0; i < N + M; ++i) {
        if (curInD[i] == 0) {
            que.push(i);
        }
    }

    int num = 0;
    while ( !que.empty()) {
        int cur = que.front();
        que.pop();
        ++num;

        for (int i = 0; i < tab[cur].size(); ++i) {
            int nex = tab[cur][i];

            if (curInD[nex] != 0) {
                --curInD[nex];
                if (curInD[nex] == 0) {
                    que.push(nex);
                }
            }
        }
    }

    if (num == N + M) {
        return false;
    }
    else {
        return true;
    }
}

void compute(int N, int M) {
    bool ini[MAXN] = {false};

    int curInD[MAXN + MAXM];
    memcpy(curInD, InD, sizeof(InD));

    queue<int> que;  // 记录入度为0
    for (int i = 0; i < N + M; ++i) {
        if (curInD[i] == 0) {
            que.push(i);
        }
    }

    while ( !que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < tab[cur].size(); ++i) {
            int nex = tab[cur][i];

            if (curInD[nex] != 0) {
                --curInD[nex];

                // 器件未被初始化过， 没遇到过输入
                if (ini[nex - M] == false) {
                    output[nex] = output[cur];
                    ini[nex - M] = true;
                    if (type[nex - M] == "NOT") {
                        output[nex] = !output[nex];
                    }
                }
                // 遇见过输入
                else {
                    if (type[nex - M] == "AND" || type[nex - M] == "NAND") {
                        output[nex] = output[nex] & output[cur];
                    }
                    else if (type[nex - M] == "OR" || type[nex - M] == "NOR") {
                        output[nex] = output[nex] | output[cur];
                    }
                    else if (type[nex - M] == "XOR") {
                        output[nex] = output[nex] ^ output[cur];
                    }
                }

                if (curInD[nex] == 0) {
                    que.push(nex);
                    if (type[nex - M] == "NOR" || type[nex - M] == "NAND") {
                        output[nex] = !output[nex];
                    }
                }
            }
        }
    }
}

int main() {
    int Q;
    cin>>Q;

    for (int q = 0; q < Q; ++q) {
        int M, N;
        cin>>M>>N;

        fill(InD, InD + MAXM + MAXN, 0);  // 初始化入度  // 清理

        // 输入器件信息， 构建邻接表
        for (int n = 0; n < N; ++n) {
            cin>>type[n];
            int K;  // 每个器件的输入数
            cin>>K;

            InD[n + M] = K;  // 记录器件入度数
            for (int k = 0; k < K; ++k) {
                string t;
                cin>>t;

                int pre = atoi(t.substr(1).c_str()) - 1;  // -1, start from 0
                if (t[0] == 'O') {             // 器件编号 （-1+m)
                    pre += M;
                }
                tab[pre].emplace_back(n + M);  // 构建邻接表
            }
        }

        // S个输入
        int S;
        cin>>S;
        // S个输入的输入
        for (int s = 0; s < S; ++s) {
            input.emplace_back();
            for (int m = 0; m < M; ++m) {
                int cur;
                cin>>cur;
                input[s].emplace_back(cur);
            }
        }
        // S个输入对应要求输出的器件的编号
        for (int s = 0; s < S; ++s) {
            outputDev.emplace_back();
            int num;
            cin>>num;
            for (int n = 0; n < num; ++n) {
                int cur;
                cin>>cur;
                cur += (M - 1);
                outputDev[s].emplace_back(cur);
            }
        }

        // 成环
        if (topologicalSort(N, M)) {
            cout<<"LOOP"<<endl;
        }
        // 不成环
        else {
            for (int s = 0; s < S; ++s) {
                // 初始化
                fill(output, output + MAXN + MAXM, 0);  // 清理
                for (int i = 0; i < M; ++i) {
                    output[i] = input[s][i];
                }

                compute(N, M);

                // 输出
                for (int i = 0; i < outputDev[s].size(); ++i) {
                    cout<<output[outputDev[s][i]]<<" ";
                }
                cout<<endl;
            }
        }

        // 清理一下
        input.clear();
        outputDev.clear();
        for (int i = 0; i < MAXN + MAXM; i++) {
            tab[i].clear();
        }
        /*
        for (int i = 0; i < MAXN; ++i) {
            type[i] = "";
        }
        */
    }

    return 0;
}





