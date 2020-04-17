#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Quick_Sort(int *,int,int);
int position(int *,int,int,int);

int main()
{
	
	int i,*num,n;
	printf("Enter The No Of Numbers :\t");
	scanf("%d",&n);

	num=(int *)malloc(n*sizeof(int));

	printf("Enter The %d Numbers \t",n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);

	Quick_Sort(num,0,n-1);

	printf("The Sorting Numbers Are Given Bellow\n");
	for(i=0;i<n;i++)
		printf("%d\t",num[i]);
	printf("\n");
	
}

void Quick_Sort(int num[],int s,int e)
{
	int size,p;
	
	if(s == e)
		return;
	
	size=e-s+1;
	p=s+(rand()%size);

	p=position(num,num[p],s,e);
	
	if(s<p)
		Quick_Sort(num,s,p-1);
	if(p<e)
		Quick_Sort(num,p+1,e);
}

int position(int num[],int pivot,int s,int e)
{
	int c;

	while(1)
	{

		while(num[s]<pivot)
			s++;

		while(pivot<num[e])
			e--;

		if(s == e)
			return s;

		c=num[s];
		num[s]=num[e];
		num[e]=c;
		
		if(num[e]==num[s])	
			e--;
	}

}
