#include<stdio.h>
#include<stdlib.h>

int *num,n;

void heap_sort();
void swap(int i,int j);

int main()
{
	int i;
	printf("Enter The No Of Numbers :\t");
	scanf("%d",&n);

	num=(int *)malloc(n*sizeof(int));

	printf("Enter The %d Numbers \t",n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);

	heap_sort();

	printf("The Sorting Numbers Are Given Bellow\n");
	for(i=0;i<n;i++)
		printf("%d\t",num[i]);
	printf("\n");
}

void heap_sort()
{
	int i,largest,l,k,r,t,j;
	
	for(k=0;k<n/2;k++)
	{
		for (int i = n / 2 - 1; i >= k; i--)
		{
			int largest = i;
			int l = 2*i + 1;
			int r = 2*i + 2;
		
			if (l < n && num[l] > num[largest])
				largest = l;
			
			if (r < n && num[r] > num[largest])
				largest = r;
			if (largest != i)
				swap(largest,i);
		}	
	}

	for(j=n-1;j>0;j--)
	{
		t=0;
		swap(j,0);
		while(t<j)
		{
			int l=2*t+1;
			
			if(l<j-1 && num[l+1]>num[l])
				l++;
			if(l<j && num[l]>num[t])
				swap(l,t);
			t=l;

		}
	}
}

void swap(int i,int j)
{
	int p;

	p=num[i];
	num[i]=num[j];
	num[j]=p;
}
