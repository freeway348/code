#include <iostream>
using namespace std;
int main(){
	//接收数据
	int r, y, g;		//红，黄，绿灯的时长 
	cin >>r >>y >>g;
	int n;				 
	cin >>n; 
	
	//计算
	long long all_time = 0; 			//总时间 
	int state = -1;				//出发时刻每个灯的状态
	int time = -1;				//出发时刻每个灯上显示的时间 
	int roll_time = r+y+g;		//红绿灯一轮的时间 
	for(int i=0; i<n; i++){
		cin >> state >>time;	//接收数据 
		
		if(state == 0){			//走一段路，直接加时间 
			all_time += time;
		}
		if(state == 1){			//初始是红灯 （绿-->黄-->红） 
			long long temp = all_time - time;
			if(temp < 0){	//到达时，红灯还没有结束 
				all_time = time;			//直接就要等于一开始红灯剩余的时间 
				continue; 
			} 
			else{
				temp = temp % roll_time;
				if(temp >= g){		//处于黄灯或红灯状态下 
					all_time += (roll_time - temp); 
				} 
			}
		}
		if(state == 2){			//初始是黄灯  （红-->绿-->黄） 
			long long temp = all_time - time;
			if(temp < 0){		//到达时，黄灯还没有结束 
				all_time = time; 	//直接就要等于一开始黄灯剩余的时间
				all_time += r;		//再加上红灯的时间  
			}
			else{
				temp = temp % roll_time;
				if(temp < r){		//处于红灯状态下 
					all_time += (r - temp);
				} 
				else if(temp >= r+g){	//处于黄灯状态下 
					all_time += (roll_time - temp);	//加上黄灯剩余时间 
					all_time += r; 		//再加上红灯时间 
				}
			} 
		}
		if(state == 3){			// 初始是绿灯  （黄-->红-->绿） 
			long long temp = all_time - time;
			if(temp < 0){		//到达时，绿灯未结束，直接过 
				continue;
			}
			else{
				temp = temp % roll_time;
				if(temp < y+r){
					all_time += (y+r-temp);
				}
			} 
		} 
	} 
	
	//输出结果
	cout <<all_time<<endl; 
	return 0;
} 

