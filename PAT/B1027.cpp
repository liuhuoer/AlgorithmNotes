#include <cstdio>
#include <cmath>

int main()
{
	int n, k, sum = 0;
	char c;
	scanf("%d %c", &n, &c);
	k = (int)sqrt(2.0 * (n + 1)) - 1; //## !! 
	if(k % 2 == 0)
		--k;
	sum = (1 + k) * (1 + k) / 2 - 1;


	for(int i = k; i >= 1; i -= 2)
	{
		for(int j = 0; j < (k - i) / 2; ++j)
			printf(" ");
		for(int j = 0; j < i; ++j)
			printf("%c", c);
		printf("\n");
	}
	for(int i = 3; i <= k; i += 2) {
		for(int j = 0; j < (k - i) / 2; ++j)
			printf(" ");
		for(int j = 0; j < i; ++j)
			printf("%c", c);
		printf("\n");
	}

	printf("%d", n - sum);

	return 0;
}
