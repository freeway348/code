# -*- coding: GB2312 -*-
def isNum(str):
    for i in str:
        if not(i.isdigit()): #�ж��Ƿ�ȫΪ���֣������ַ���false
            return False
    return True    #����TRUE��ʾȫΪ�������
def isChar(str):
    chars = list(str) #���ַ���strת��Ϊ�ַ�����
    isPhontic = False
    for i in chars:
        isPhontic = (i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z')
        if not isPhontic:
            return False
    return True   
def Encryption(plaintext, key):
    print("���ܺ�Ϊ��")
    for i in range(len(plaintext)):
        #ord():���ַ�תASCII�룬chr()����ASCII��ת�ַ�
        if ord('a') <= ord(plaintext[i]) <= ord('z'):  
            print(chr((ord(plaintext[i]) + key - ord('a')) % 26 + ord('a')),end="")
        elif ord('A') <= ord(plaintext[i]) <= ord('Z'):
            print(chr((ord(plaintext[i]) + key - ord('A')) % 26 + ord('A')),end="")
def Decrypt(ciphertext, key):
    print("���ܺ�Ϊ��")
    for i in range(len(ciphertext)):
        if ord('a') <= ord(ciphertext[i]) <= ord('z'):
            print(chr((ord(ciphertext[i]) + (0 - key) - ord('a')) % 26 + ord('a')),end="")
        elif ord('A') <= ord(ciphertext[i]) <= ord('Z'):
            print(chr((ord(ciphertext[i]) + (0 - key) - ord('A')) % 26 + ord('A')),end="")            
def operate1():
    plaintext = input("���������ģ�") #plaintext����
    plaintext = plaintext.replace(" ","") #ȥ��ciphertext�����еĿո�
    while(isChar(plaintext) == False): #�ж�plaintext�����Ƿ�ȫΪ��ĸ�ַ�
        plaintext = input("����������ȫ��ĸ�ַ����ģ�") #��������
    key = input("��������Կ��")
    while(isNum(key) == False): #�����Կkey��ȫΪ����
        key = input("��Կ���������֣�������ѡ��") 
    Encryption(plaintext,int(key)) #ʹ��key������plaintext����
def operate2():
    ciphertext = input("���������ģ�")
    ciphertext = ciphertext.replace(" ","")
    while(isChar(ciphertext) == False): #��������к��з���ĸ�ַ�����
        ciphertext = input("����������ȫ��ĸ�ַ����ģ�")
    key = input("��������Կ��")
    while(isNum(key) == False): #�����Կkey��ȫΪ����
        key = input("��Կ���������֣�������ѡ��")
    Decrypt(ciphertext,int(key)) #ʹ��key������ciphertext����
def operate3():
    print("�˳��ɹ�")
    exit(0)
###################������############
operateType = "0"
OperateAll = {"1" : operate1, "2" : operate2, "3" : operate3} #�ֵ����
while(operateType != 3):
    print("\n")
    print("**********ѡ����**********")
    print("1.���ļ���  2.���Ľ���  3.�˳�")
    print("***************************")
    operateType = input("��ѡ���ܣ�")
    while(isNum(operateType) == False): #��������operateType�ַ�������
        operateType = input("������ѡ��")
    OperateAll[operateType]() #���ú���

