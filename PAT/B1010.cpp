#include <cstdio>

int main()
{
	int a[1010] = {0};
	int d, e, count = 0;
	for(; scanf("%d%d", &d, &e) != EOF;)
		a[e] = d;
	
	//求导
	a[0] = 0;
	for(int i = 1; i < 1000; ++i)
	{
		a[i - 1] = a[i] * i;
		a[i] = 0;
		if(a[i - 1] != 0)
			++count;
	}

	//output
	if(count = 0) 
		printf("0 0");
	for(int i = 1000; i >= 0; --i)
	{
		if(a[i] != 0)
		{
			printf("%d %d", a[i], i);
			if(--count)
				printf(" ");
		}
	}

	return 0;
}
