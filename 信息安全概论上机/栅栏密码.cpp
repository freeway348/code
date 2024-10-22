#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 栅栏加密函数
string railFenceEncrypt(string text, int rails) {
    vector<string> rail(rails);
    int dir = 1, row = 0;
    for (char c : text) {
        if (c != ' ')
        {
            rail[row] += c;
            row += dir;
            if (row == rails) {
                row = 0;  // 变换方向
            }
        }
    }
    string result = "";
    for (string r : rail) {
        result += r;  // 将所有轨道的字符连接
    }
    return result;
}

// 栅栏解密函数
string railFenceDecrypt(string cipher, int rails) {
    vector<string> rail(rails);
    vector<int> len(rails, 0);
    int dir = 1, row = 0, k = 0;

    // 计算每个轨道应分配的字符数
    for (int i = 0; i < cipher.length(); i++) {
        len[row]++;
        row += dir;
        if (row == rails) {
            row = 0;
        }
    }

    // 将密文填充到每个轨道
    for (int i = 0; i < rails; i++) {
        rail[i] = cipher.substr(k, len[i]);
        k += len[i];
    }

    // 读取字符还原明文
    string result = "";
    dir = 1, row = 0;
    vector<int> pos(rails, 0);
    for (int i = 0; i < cipher.length(); i++) {
        result += rail[row][pos[row]++];
        row += dir;
        if (row == rails) {
            row = 0;
        }
    }
    return result;
}

int main() {
    string plaintext = "HELLO";
    int rails = 3;

    string encrypted = railFenceEncrypt(plaintext, rails);
    string decrypted = railFenceDecrypt(encrypted, rails);

    cout << "明文: " << plaintext << endl;
    cout << "加密: " << encrypted << endl;
    cout << "解密: " << decrypted << endl;

    return 0;
}
