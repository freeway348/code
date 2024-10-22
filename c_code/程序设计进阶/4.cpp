#include <iostream>
#include <vector>
#include <queue>  // queue
#include <string.h>  // memcpy ...
#include <algorithm>  // atoi�� fill

using namespace std;

// ����
const int MAXK = 5;
const int MAXN = 501;
const int MAXM = 2501;  // k * N
const int MAXS = 100001;

// ����
vector<int> tab[MAXN + MAXM]; // �ڽӱ���������������� dce[i][j]: i->j
string type[MAXN];            // ÿ������������
int InD[MAXN + MAXM];         // ÿ����������������

// ����
vector<vector<int> > input;     // ����
vector<vector<int> > outputDev;  // ÿ������Ҫ��������������

// ���
int output[MAXN + MAXM];  // ����������Ľ��


// �ж��ڽӱ��ǲ��������޻�ͼ
bool topologicalSort(int  N, int M) {
    int curInD[MAXN + MAXM];
    memcpy(curInD, InD, sizeof(InD));

    queue<int> que;  // ��¼���Ϊ0
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

    queue<int> que;  // ��¼���Ϊ0
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

                // ����δ����ʼ������ û����������
                if (ini[nex - M] == false) {
                    output[nex] = output[cur];
                    ini[nex - M] = true;
                    if (type[nex - M] == "NOT") {
                        output[nex] = !output[nex];
                    }
                }
                // ����������
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

        fill(InD, InD + MAXM + MAXN, 0);  // ��ʼ�����  // ����

        // ����������Ϣ�� �����ڽӱ�
        for (int n = 0; n < N; ++n) {
            cin>>type[n];
            int K;  // ÿ��������������
            cin>>K;

            InD[n + M] = K;  // ��¼���������
            for (int k = 0; k < K; ++k) {
                string t;
                cin>>t;

                int pre = atoi(t.substr(1).c_str()) - 1;  // -1, start from 0
                if (t[0] == 'O') {             // ������� ��-1+m)
                    pre += M;
                }
                tab[pre].emplace_back(n + M);  // �����ڽӱ�
            }
        }

        // S������
        int S;
        cin>>S;
        // S�����������
        for (int s = 0; s < S; ++s) {
            input.emplace_back();
            for (int m = 0; m < M; ++m) {
                int cur;
                cin>>cur;
                input[s].emplace_back(cur);
            }
        }
        // S�������ӦҪ������������ı��
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

        // �ɻ�
        if (topologicalSort(N, M)) {
            cout<<"LOOP"<<endl;
        }
        // ���ɻ�
        else {
            for (int s = 0; s < S; ++s) {
                // ��ʼ��
                fill(output, output + MAXN + MAXM, 0);  // ����
                for (int i = 0; i < M; ++i) {
                    output[i] = input[s][i];
                }

                compute(N, M);

                // ���
                for (int i = 0; i < outputDev[s].size(); ++i) {
                    cout<<output[outputDev[s][i]]<<" ";
                }
                cout<<endl;
            }
        }

        // ����һ��
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





