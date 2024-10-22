#include<stdio.h>
#include<string.h>
int jinwei = 0;

int invert(char *s){
    int i=0,j,l;
    char temp;
    l = strlen(s);
    j = l-1;
    while(s[i]=='0'){
        l--;
        s[i] = s[j];
        s[j] = '\0';
        i++;
        j--;
    }
    for(;j>i;i++,j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return l;
}

char add(int a, int b){
    int temp;
    temp = (a+b)%10+jinwei;
    jinwei = (a+b)/10;
    if(temp==10){
        temp = 0;
        jinwei++;
    }
    return temp+'0';
}

//进行字符与数字的转换
void CharTranslateToInt(int pi[],char pc[],int i){
	pi[i] = (int)(pc[i]) - 48;
}

int main(void){
	
	int i,j,k,temp,shi,ge,num1len,num2len;
	int num1[100] = {0}, num2[100] = {0};
	char str[100]; 
	int sum[200] = {0};
	char a[128],b[128],res[128]="";
    int la,lb,lres;
    gets(a);
    gets(str);
    gets(b);
 	if (str=="+")
 	{
 		la = invert(a);
	    lb = invert(b);
	    for(i=0;i<la&&i<lb;i++){
	        res[i] = add(a[i]-'0',b[i]-'0');
	    }
	    if(la<lb){
	        for(;b[i]!='\0';i++){
	            res[i] = add(0,b[i]-'0');
	        }
	    }
	    else{
	        for(;a[i]!='\0';i++){
	            res[i] = add(a[i]-'0',0);
	        }
	    }
	    if(jinwei==1)
	        res[i++] = '1';
	    res[i] = '\0';
	    lres = strlen(res);
	    for(i=lres-1;i>=0;i--)
	        printf("%c",res[i]);
	    printf("\n");
	    getchar();
	 }
    else 
	{
		num1len = strlen(a); 
		for(i = 0; i < num1len; i++){
			CharTranslateToInt(num1,a,i);
		}
		num2len = strlen(b);
		for(i = 0; i < num2len; i++){
			CharTranslateToInt(num2,b,i);
		}
	//这里将每一次相乘的数加到对应位置上
		for(i = num1len - 1; i >= 0; i--){
			for(j = num2len - 1; j >= 0; j--){
				temp = num1[i] * num2[j];
				sum[num1len + num2len - 2 - i - j] += temp;
			}
		}
	//接下来统一每一位满十往上一位进一
		for(i = 0; i < 199; i++){
			ge = sum[i] % 10;
			shi = sum[i] / 10;
			sum[i] = ge;
			sum[i+1] += shi; 
		}
	//从数组的末尾开始遍历，找到第一位非零数
		for(i = 199;i >= 0; i--){
			if(sum[i]){
				k = i;
				break;
			}
		} 
	//接下来就是打印结果啦
		printf("k = %d\n",k) ;
		for(i = k; i >= 0; i--){
			printf("%d",sum[i]);
	}
	}
	return 0;
} 



