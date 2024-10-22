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
	cout<<"构造了一个animal"<<endl;
}
animal::~animal()
{
	cout<<"析构了一个animal"<<endl;
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
	cout<<"构造了一个dog"<<endl;	
 } 
dog::~dog() 
{
	cout<<"析构了一个dog"<<endl;
}
void dog::SetAge(int a)
{
	age=a;
	cout<<"狗的年龄为:"<<a<<endl;
 }
int main()
{
	dog m;
	m.SetAge(3); 
 }
