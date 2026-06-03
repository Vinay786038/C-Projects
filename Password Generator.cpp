#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
string Password_Generator(int size)
{
	srand(time(0));
	string alphabates="1234567890abcd#%$&*~!@efghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string password="";
	while(size--)
	{
		password+=alphabates[rand()%70];
	}
	return password;

}
int main()
{
	int size;
	cout<<"Enter size of your password:";
	cin>>size;
	string password;
	password=Password_Generator(size);
	cout<<"Your password is:"<<endl;
	cout<<password;
}

