#include <iostream>
#include <string>
using namespace std;

// �������ܺ���
string caesarEncrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) { // �������ĸ
            char shift = isupper(text[i]) ? 'A' : 'a'; // �жϴ�Сд��������׼ 
            result += char(int((text[i] - shift + key) % 26 + shift));
        } else {
            result += text[i];  // ����ĸ�ַ����ֲ���
        }
    }
    return result;
}

// �������ܺ���
string caesarDecrypt(string text, int key) {
    return caesarEncrypt(text, -key);  // �����Ǽ��ܵ�������
}

int main() {
    string plaintext = "HELLO";
    int key = 3;

    string encrypted = caesarEncrypt(plaintext, key);
    string decrypted = caesarDecrypt(encrypted, key);

    cout << "����: " << plaintext << endl;
    cout << "����: " << encrypted << endl;
    cout << "����: " << decrypted << endl;

    return 0;
}
