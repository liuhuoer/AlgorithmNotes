#include <cstdio>

bool judge(int * res, int num)
{
	for(int i = 0; i <= num / 2; i++)
	{
		if(res[i] != res[num - i - 1])
		{
			return false;
		}
	}
	return true;

}

int main()
{
	int num, p, count = 0;
	int res[40];
	scanf("%d %d", &num, &p);
	do{
		res[count++] = num % p;
		num /= p;
	}while(num != 0);

	if(judge(res, count))
		printf("Yes\n");
	else
		printf("No\n");

	for(int i = count - 1; i >= 0; --i)
	{
		printf("%d", res[i]);
		if(i > 0)
			printf(" ");
	}

	return 0;
}


/*
Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1
*/
