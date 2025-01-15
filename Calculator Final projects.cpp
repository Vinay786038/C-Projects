#include<stdio.h>
char menu()
{
	printf("1.Adding\n");
	printf("2.Subtract\n");
	printf("3.Multiply\n");
	printf("4.Division\n");
	printf("5.Modulus\n");
	printf("6.Percentage\n");
	printf("7.Exit\n");
}
int main()
{
	int num;
	do
	{
		menu();
		printf("You enter your choice:");
		scanf("%d",&num);
		if(num==1)
		{
			int a,b,res;
			printf("Enter first number:");
			scanf("%d",&a);
			printf("Enter second number:");
			scanf("%d",&b);
			printf("Final Answer:%d\n",a+b);
		}
		else if(num==2)
		{
			int a,b,res;
			printf("Enter first number:");
			scanf("%d",&a);
			printf("Enter second number:");
			scanf("%d",&b);
			printf("Final result:%d\n",a-b);
		}
		else if(num==3)
		{
			int a,b,res;
			printf("Enter first number:");
			scanf("%d",&a);
			printf("Enter second number:");
			scanf("%d",&b);
			printf("Final result:%d\n",a*b);
		}
		else if(num==4)
		{
			int a,b,res;
			printf("Enter first number:");
			scanf("%d",&a);
			printf("Enter second number:");
			scanf("%d",&b);
			if(b==0)
			{
				printf("Sorry second number is not equal to:0 please try again\n");
			}
			else
			printf("Final Result:%d\n",a/b);
		}
		else if(num==5)
		{
			int a,b,res;
			printf("Enter first number:");
			scanf("%d",&a);
			printf("Enter second number:");
			scanf("%d",&b);
			if(b==0)
			{
				printf("Sorry second number is not equal to:0 please try again\n");
			}
			else
			printf("Final Result:%d\n",a%b);
		}
		else if(num==6)
		{
			int a,b,res;
			printf("Enter that number find percentage:");
			scanf("%d",&a);
			printf("Enter MM:");
			scanf("%d",&b);
			printf("Final result:%d%%\n",a*100/b);
		}
		else if(num==7)
		break;
		
		else
		{
			printf("Please enter right choice\n");
		}
	}while(num!=7);
}
	


