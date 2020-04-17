#include<stdio.h>
#include<stdlib.h>

void Bubble_Sort(int *,int);

int main()
{
	int i,*num,n;
	printf("Enter The No Of Numbers :\t");
	scanf("%d",&n);

	num=(int *)malloc(n*sizeof(int));

	printf("Enter The %d Numbers \t",n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);

	Bubble_Sort(num,n);

	printf("The Sorting Numbers Are Given Bellow\n");
	for(i=0;i<n;i++)
		printf("%d\t",num[i]);
	printf("\n");
}

void Bubble_Sort(int num[],int n)
{
	int i,j,k,t;
	
	for(i=0;i<n;i++)
	{
		k=1;

		for(j=0;j<n-i-1;j++)
		{
			
			if(num[j]>num[j+1])
			{
				t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
				k=k*0;
			}
		}

		if(k==1)
			break;
	}
}
