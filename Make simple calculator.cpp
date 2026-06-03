#include<iostream>
using namespace std;
float calculator(int m,int n,int c)
{
	if(c==1)
	return m+n;
	else if(c==2)
	return m-n;
	else if(c==3)
	return m*n;
	else if(c==4)
	{
		if(n>0)
		{
			return m/n;
		}
		else
		{
			cout<<"Your number does not divide by zero!!!!!"<<endl;
			return m;
		}
	}
	else if(c==5)
	{
		if(n>0)
		{
			return m%n;
		}
		else
		{
			cout<<"Your number does not remind by zero!!!!!"<<endl;
			return m;
		}
			
	}
	else if(c==7)
	{
		cout<<"Thank you for using my calculator!!!!!!"<<endl;
		cout<<"Created by Vinay Yadav !!!!!!!"<<endl;
		return m;
	}
	else
	{
		cout<<"You Enter Wrong choice !!!!!"<<endl;
		cout<<"Please try Again!!!!!"<<endl;
		return m;
	}
}
int main()
{
	int n;
	char c;
	float res=0;
	do
	{
		cout<<"!!!! Welcome to my Calculator !!!!!!"<<endl;
		cout<<"!!!! For Addition Enter +: !!!!"<<endl;
		cout<<"!!!! For Subtraction Enter -: !!!!"<<endl;
		cout<<"!!!! For Multiplication Enter *: !!!!"<<endl;
		cout<<"!!!! For Division Enter /: !!!!"<<endl;
		cout<<"!!!! For Modulus Enter %: !!!!"<<endl;
		cout<<"!!!! For Reset Enter R: !!!!"<<endl;
		cout<<"!!!! For Exit Enter E :!!!!!"<<endl;
		cin>>c;
		switch(c)
		{
			case '+':
				cout<<"Enter value:"<<endl;
				cin>>n;
				res=calculator(res,n,1);
				cout<<"Ans="<<res<<endl;
				break;
			case '-':
				cout<<"Enter value:"<<endl;
				cin>>n;
				res=calculator(res,n,2);
				cout<<"Ans="<<res<<endl;
				break;
			case '*':
				cout<<"Enter value:"<<endl;
				cin>>n;
				res=calculator(res,n,3);
				cout<<"Ans="<<res<<endl;
				break;
			case '/':
				cout<<"Enter value:"<<endl;
				cin>>n;
				res=calculator(res,n,4);
				cout<<"Ans="<<res<<endl;
				break;
			case '%':
				cout<<"Enter value:"<<endl;
				cin>>n;
				res=calculator(res,n,5);
				cout<<"Ans="<<res<<endl;
				break;
			case 'R':
				res=0;
				cout<<"Ans="<<res<<endl;
				break;
			case 'E':
				res=calculator(res,n,7);
				break;
			default:
				cout<<"Wrong choice Try Again!!!!!"<<endl;
		}
	}while(c!='E');
}
