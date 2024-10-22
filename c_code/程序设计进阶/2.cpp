#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m;
double r;
double a, b, c, p, s, h;
double aa, bb, cc;
double angleC, alpha, beta, delta;
double dot[2010][110];
double sq[2010][2010], si[2010][2010], dis[2010][2010];
double ans[2010];
int main(){
    scanf("%d%d%lf",&n, &m, &r);
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++){
            scanf("%lf", &dot[i][j]); //读入双精度浮点数需要用lf
        }
    }
    for(int i=0;i<=m;i++){
        sq[i][i] = 0, si[i][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<i;j++){ //只计算半个矩阵
            sq[i][j]=0;
            for(int k=0;k<n;k++){
                sq[i][j] += ((dot[i][k]-dot[j][k])*(dot[i][k]-dot[j][k])); //预处理m+1个点之间的距离和距离的平方
            }
            si[i][j] = sqrt(sq[i][j]);
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<i;j++){
            a = si[i][0]; //海伦-秦九韶公式
            b = si[j][0];
            c = si[i][j];
            p = (a+b+c)/2;
            s = sqrt(p*(p-a)*(p-b)*(p-c));
            h = 2*s/c;
            if(h>=r){
                dis[i][j] = si[i][j]; //直线距离
                dis[j][i] = si[i][j];
            }
            else{  //计算除圆心角之外的两个角度
                aa = sq[i][0];
                bb = sq[j][0];
                cc = sq[i][j];
                if(bb+cc<=aa||aa+cc<=bb){ //简化，使用余弦公式判断角是不是钝（直）角
                    dis[i][j] = si[i][j]; //直线距离
                    dis[j][i] = si[i][j];
                }
                else{
                    angleC = acos(fmax(fmin((aa+bb-cc)/2/a/b, 1), -1)); //防止浮点数误差使acos参数越界
                    alpha = acos(r/a);
                    beta = acos(r/b);
                    delta = angleC-alpha-beta;
                    dis[i][j] = sqrt(aa-r*r)+sqrt(bb-r*r)+delta*r; //三段拼成的距离
                    dis[j][i] = dis[i][j];
                    
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        ans[i]=0;
        for(int j=1;j<=m;j++){
            ans[i] += dis[i][j];
        }
        printf("%.15f\n", ans[i]);
    }
}

