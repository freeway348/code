#include <iostream>
using namespace std;
int main(){
	//��������
	int r, y, g;		//�죬�ƣ��̵Ƶ�ʱ�� 
	cin >>r >>y >>g;
	int n;				 
	cin >>n; 
	
	//����
	long long all_time = 0; 			//��ʱ�� 
	int state = -1;				//����ʱ��ÿ���Ƶ�״̬
	int time = -1;				//����ʱ��ÿ��������ʾ��ʱ�� 
	int roll_time = r+y+g;		//���̵�һ�ֵ�ʱ�� 
	for(int i=0; i<n; i++){
		cin >> state >>time;	//�������� 
		
		if(state == 0){			//��һ��·��ֱ�Ӽ�ʱ�� 
			all_time += time;
		}
		if(state == 1){			//��ʼ�Ǻ�� ����-->��-->�죩 
			long long temp = all_time - time;
			if(temp < 0){	//����ʱ����ƻ�û�н��� 
				all_time = time;			//ֱ�Ӿ�Ҫ����һ��ʼ���ʣ���ʱ�� 
				continue; 
			} 
			else{
				temp = temp % roll_time;
				if(temp >= g){		//���ڻƵƻ���״̬�� 
					all_time += (roll_time - temp); 
				} 
			}
		}
		if(state == 2){			//��ʼ�ǻƵ�  ����-->��-->�ƣ� 
			long long temp = all_time - time;
			if(temp < 0){		//����ʱ���Ƶƻ�û�н��� 
				all_time = time; 	//ֱ�Ӿ�Ҫ����һ��ʼ�Ƶ�ʣ���ʱ��
				all_time += r;		//�ټ��Ϻ�Ƶ�ʱ��  
			}
			else{
				temp = temp % roll_time;
				if(temp < r){		//���ں��״̬�� 
					all_time += (r - temp);
				} 
				else if(temp >= r+g){	//���ڻƵ�״̬�� 
					all_time += (roll_time - temp);	//���ϻƵ�ʣ��ʱ�� 
					all_time += r; 		//�ټ��Ϻ��ʱ�� 
				}
			} 
		}
		if(state == 3){			// ��ʼ���̵�  ����-->��-->�̣� 
			long long temp = all_time - time;
			if(temp < 0){		//����ʱ���̵�δ������ֱ�ӹ� 
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
	
	//������
	cout <<all_time<<endl; 
	return 0;
} 

