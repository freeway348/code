# -*- coding: GB2312 -*-
def isNum(str):
    for i in str:
        if not(i.isdigit()): #判断是否全为数字，非数字返回false
            return False
    return True    #返回TRUE表示全为数字组成
def isChar(str):
    chars = list(str) #将字符串str转换为字符数组
    isPhontic = False
    for i in chars:
        isPhontic = (i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z')
        if not isPhontic:
            return False
    return True   
def Encryption(plaintext, key):
    print("加密后为：")
    for i in range(len(plaintext)):
        #ord():把字符转ASCII码，chr()：把ASCII码转字符
        if ord('a') <= ord(plaintext[i]) <= ord('z'):  
            print(chr((ord(plaintext[i]) + key - ord('a')) % 26 + ord('a')),end="")
        elif ord('A') <= ord(plaintext[i]) <= ord('Z'):
            print(chr((ord(plaintext[i]) + key - ord('A')) % 26 + ord('A')),end="")
def Decrypt(ciphertext, key):
    print("解密后为：")
    for i in range(len(ciphertext)):
        if ord('a') <= ord(ciphertext[i]) <= ord('z'):
            print(chr((ord(ciphertext[i]) + (0 - key) - ord('a')) % 26 + ord('a')),end="")
        elif ord('A') <= ord(ciphertext[i]) <= ord('Z'):
            print(chr((ord(ciphertext[i]) + (0 - key) - ord('A')) % 26 + ord('A')),end="")            
def operate1():
    plaintext = input("请输入明文：") #plaintext明文
    plaintext = plaintext.replace(" ","") #去除ciphertext密文中的空格
    while(isChar(plaintext) == False): #判断plaintext明文是否全为字母字符
        plaintext = input("请重新输入全字母字符明文：") #输入明文
    key = input("请输入秘钥：")
    while(isNum(key) == False): #如果秘钥key非全为数字
        key = input("秘钥必须是数字，请重新选择：") 
    Encryption(plaintext,int(key)) #使用key对明文plaintext加密
def operate2():
    ciphertext = input("请输入密文：")
    ciphertext = ciphertext.replace(" ","")
    while(isChar(ciphertext) == False): #如果密文中含有非字母字符符号
        ciphertext = input("请重新输入全字母字符密文：")
    key = input("请输入秘钥：")
    while(isNum(key) == False): #如果秘钥key非全为数字
        key = input("秘钥必须是数字，请重新选择：")
    Decrypt(ciphertext,int(key)) #使用key对密文ciphertext解密
def operate3():
    print("退出成功")
    exit(0)
###################主函数############
operateType = "0"
OperateAll = {"1" : operate1, "2" : operate2, "3" : operate3} #字典操作
while(operateType != 3):
    print("\n")
    print("**********选择功能**********")
    print("1.明文加密  2.密文解密  3.退出")
    print("***************************")
    operateType = input("请选择功能：")
    while(isNum(operateType) == False): #如果输入的operateType字符非数字
        operateType = input("请重新选择：")
    OperateAll[operateType]() #调用函数

