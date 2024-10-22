#include <iostream>
#include <string>
#include <vector>
using namespace std;

// դ�����ܺ���
string railFenceEncrypt(string text, int rails) {
    vector<string> rail(rails);
    int dir = 1, row = 0;
    for (char c : text) {
        if (c != ' ')
        {
            rail[row] += c;
            row += dir;
            if (row == rails) {
                row = 0;  // �任����
            }
        }
    }
    string result = "";
    for (string r : rail) {
        result += r;  // �����й�����ַ�����
    }
    return result;
}

// դ�����ܺ���
string railFenceDecrypt(string cipher, int rails) {
    vector<string> rail(rails);
    vector<int> len(rails, 0);
    int dir = 1, row = 0, k = 0;

    // ����ÿ�����Ӧ������ַ���
    for (int i = 0; i < cipher.length(); i++) {
        len[row]++;
        row += dir;
        if (row == rails) {
            row = 0;
        }
    }

    // ��������䵽ÿ�����
    for (int i = 0; i < rails; i++) {
        rail[i] = cipher.substr(k, len[i]);
        k += len[i];
    }

    // ��ȡ�ַ���ԭ����
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

    cout << "����: " << plaintext << endl;
    cout << "����: " << encrypted << endl;
    cout << "����: " << decrypted << endl;

    return 0;
}
