#include <cstdio>

int main()
{
	int num, p, count = 0;
	int res[40];
	scanf("%d %d", &num, &p);
	do{
		res[count++] = num % p;
		num /= p;
	}while(num != 0);

	for(int i = 0; i <= num / 2; i++)
	{
		if(res[i] == res[count - i - 1])
			printf("Yes\n");
		else
			printf("No\n");
	}
	for(int i = count - 1; i >= 0; --i)
		printf("%d", res[i]);

	return 0;
}
