#include<stdio.h>
#include<stdlib.h>

void insertion(int n);

int *num;

int main()
{
	int n,i;
	printf("Enter The No Of Numbers :\t");
	scanf("%d",&n);

	num=(int *)malloc(n*sizeof(int));

	printf("Enter The %d Numbers \t",n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	
	insertion(n);
	
	printf("The Sorting Numbers Are Given Bellow\n");
	for(i=0;i<n;i++)
		printf("%d\t",num[i]);
	printf("\n");
}

void insertion(int n)
{
	int i,current,j;

	for(i=0;i<n;i++)
	{
		current=num[i];
		j=i-1;
		
		while(j>=0 && num[j]>current)
		{
			num[j+1]=num[j];
			j=j-1;
		
		}
		num[j+1]=current;	
	}
}
