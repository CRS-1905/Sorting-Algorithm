#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node point;

point *p[10],*head[10];

void Radix_Sort(int *,int);
int max(int num[],int n);
int num_digit(int x);
int significant_bit(int r,int s1);
void insert(int i,int d);
int pop(int i);

int main()
{
	int i,*num,n;
	printf("Enter The No Of Numbers :\t");
	scanf("%d",&n);

	num=(int *)malloc(n*sizeof(int));

	printf("Enter The %d Numbers \t",n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);

	Radix_Sort(num,n);

	printf("The Sorting Numbers Are Given Bellow\n");
	for(i=0;i<n;i++)
		printf("%d\t",num[i]);
	printf("\n");
}

void Radix_Sort(int num[],int n)
{
	int m,d,r,j,k,i,s;

	m=max(num,n);
	d=num_digit(m);
	
	for(i=0;i<10;i++)
		p[i]=NULL;

	for(i=1;i<=d;i++)
	{

		for(j=0;j<n;j++)
		{	
			r=significant_bit(num[j],i);
			insert(r,num[j]);
		}

		s=0;
		for(k=0;k<10;k++)
		{
			while(p[k]!=NULL)
			{
				num[s]=pop(k);
				s++;
			}
		}
	}
}

int max(int num[],int n)
{
	int i,max=num[0];

	for(i=1;i<n;i++)
		if(num[i]>max)
			max=num[i];
	
	return max;
}

int num_digit(int x)
{			
	int s1=0,p=1;

	while(p<=x)
	{
		s1++;
		p=10*p;
	}

	return s1;
}

int significant_bit(int r,int s1)
{
	if(s1==1)
		return r%10;

	for(int i=2;i<=s1;i++)
		r=r/10;	

	return(r%10);
}

void insert(int i,int d)
{
	point *new,*q;
	new=(point *)malloc(sizeof (point));
	new->data=d;
	new->next=NULL;
	if(p[i]==NULL)
		p[i]=new;
	else
	{
		q=p[i];
		while(q->next!=NULL)
			q=q->next;
		q->next=new;
	}
}

int pop(int i)
{
	int d= p[i]->data;
	p[i]=p[i]->next;
	return d;
}
