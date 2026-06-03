#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
string OTPGenerator()
{
	int size=6;//if otp=4 digit change size 6 to 4
	srand(time(0));
	string numbers="1234567890";//string is because if numbers is
	//int does not allow 0 in 1st position if 0is 1st position after that your OTP missing 1st zero
	string result="";//empty string
	while(size--)
	{
		result+=numbers[rand()%10];//%10 because answer always is 0-9
		//rand() function find random number
	}
	return result;
}
int main()
{
	string OTP;
	OTP=OTPGenerator();
	cout<<"Your OTP is :"<<OTP;
}
