#include <iostream>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class animal
{
	private:
		int age;
	public:
		animal();
		~animal();
};
animal::animal()
{
	cout<<"������һ��animal"<<endl;
}
animal::~animal()
{
	cout<<"������һ��animal"<<endl;
 }
class dog:public animal
{
	public:
	dog();
	~dog();
	void SetAge(int a);	
 };
dog::dog()
{
	cout<<"������һ��dog"<<endl;	
 } 
dog::~dog() 
{
	cout<<"������һ��dog"<<endl;
}
void dog::SetAge(int a)
{
	age=a;
	cout<<"��������Ϊ:"<<a<<endl;
 }
int main()
{
	dog m;
	m.SetAge(3); 
 }
