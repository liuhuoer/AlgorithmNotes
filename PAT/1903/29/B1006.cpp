#include <cstdio>

int main()
{
	int x, sum = 0, count = 0, res[3];

	//input
	scanf("%d", &x);
	//the ones, tens, hundreds place
	do{
		res[count++] = x % 10;
		x /= 10;
	}while(x != 0);
	//output 
	for(int i = count - 1; i >= 0; --i)
	{
		// the hundreds place
		if(i == 2)
		{
			for(int j = 0; j < res[i]; j++)
			{
				printf("B");
			}
		}
		//the tens place
		if(i == 1)
		{
			for(int j = 0; j < res[i]; j++)
			{
				printf("S");
			}
		}
		if(i == 0)
		{
			for(int j = 0; j < res[i]; j++)
			{
				printf("%d", j + 1);
			}
		}
	}

	return 0;
}
