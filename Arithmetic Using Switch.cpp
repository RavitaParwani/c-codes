//arithmetic operations using switch


#include<stdio.h>

int main()
{
	int a,b;
	char op;
	
	printf("Enter the two numbers \nNumber 1 : ");
	scanf("%d",&a);
	printf("\nNumber 2 : ");
	scanf("%d",&b);
	printf("\nEnter the operation");
	scanf("%c",&op);
	
	switch(op)
	{
		case '+': printf("%d", a+b);
				  break;
		case '-': printf("%d", a-b);
				  break;
		case '*': printf("%d", a*b);
				  break;
		case '/': printf("%d", a/b);
				  break;
		case '%': printf("%d", a%b);
				  break;
		default: printf("\nEnter a valid operation");
	}
	
	return 0;
}
