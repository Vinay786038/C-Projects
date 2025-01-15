#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	printf("Welcome in number Guessing Game!!\n");
	int random,guess,no_of_attempts=0;
	srand(time(NULL));
	random=rand()%100+1;
	//printf("%d\n",random);
	do{
		printf("Enter your number");
		scanf("%d",&guess);
		no_of_attempts++;
		if(guess<random)
		{
			printf("You enter smaller number\n");
			printf("Try Again!!!\n");
		}
		else if(guess>random)
		{
			printf("You enter greater number\n");
			printf("Try again!!!\n");
		}
		else
		printf("Congratulation You !!Won!! in Attempts:%d\n",no_of_attempts);
	}while(guess!=random);
	printf("Thankyou for playing!!\n\n\n\n");
	
	printf("Made by Vinay Yadav!!");
}

 
