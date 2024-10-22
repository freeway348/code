#include <iostream>
#include <string>
using namespace std;

// 凯撒加密函数
string caesarEncrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) { // 如果是字母
            char shift = isupper(text[i]) ? 'A' : 'a'; // 判断大小写来决定基准 
            result += char(int((text[i] - shift + key) % 26 + shift));
        } else {
            result += text[i];  // 非字母字符保持不变
        }
    }
    return result;
}

// 凯撒解密函数
string caesarDecrypt(string text, int key) {
    return caesarEncrypt(text, -key);  // 解密是加密的逆运算
}

int main() {
    string plaintext = "HELLO";
    int key = 3;

    string encrypted = caesarEncrypt(plaintext, key);
    string decrypted = caesarDecrypt(encrypted, key);

    cout << "明文: " << plaintext << endl;
    cout << "加密: " << encrypted << endl;
    cout << "解密: " << decrypted << endl;

    return 0;
}
