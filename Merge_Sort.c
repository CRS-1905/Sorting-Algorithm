#include<stdio.h>
#include<stdlib.h>

int *num,n;

void Merge_sort(int l,int r);
void Merge(int l,int m,int r);

int main()
{
	int i;
	printf("Enter The No Of Numbers :\t");
	scanf("%d",&n);

	num=(int *)malloc(n*sizeof(int));

	printf("Enter The %d Numbers \t",n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);

	Merge_sort(0,n-1);

	printf("The Sorting Numbers Are Given Bellow\n");
	for(i=0;i<n;i++)
		printf("%d\t",num[i]);
	printf("\n");
}

void Merge_sort(int l,int r)
{
	if(l<r)
	{
		int i;
		int m=l+((r-l)/2);
		Merge_sort(l,m);
		Merge_sort(m+1,r);
		Merge(l,m,r);
	}
}

void Merge(int l,int m,int r)
{
	int n1,n2,i,j,k;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	
	for(i=0;i<n1;i++)
		L[i]=num[l+i];
	for(j=0;j<n2;j++)
		R[j]=num[m+1+j];
	i=0;j=0;k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			num[k]=L[i];
			i++;
		}
		else
		{
			num[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		num[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		num[k]=R[j];
		j++;
		k++;
	}
}
