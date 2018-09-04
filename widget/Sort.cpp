#include <cstdio>
int main()
{
	int a[10]={3,1,4,5,2};
	//bubble sort;
	for(int i=1;i<=4;++i)
	{
		for(int j=0;j<5-i;++j)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	//simple selection sort;
	for(int i=0;i<5;++i)//ahead sort part;
	{
		int k=i;
		for(int j=i;j<5;++j)//latter unsort part;
		{
			if(a[k]>a[j])
				k=j;
		}
		int temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
	//insertion sort;
	for(int i=1;i<5;++i)
	{
		int temp=a[i],j=i;
		for(;j>1&&a[j-1]>a[j];--j)
		{
			int t=a[j-1];
			a[j-1]=a[j];
			a[j]=t;
		}
		a[j]=temp;
	}
	//##output
	for(int i=0;i<5;++i)
		printf("%d",a[i]);
	return 0;
}
