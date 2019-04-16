#include <cstdio>

int main()
{
	int a = 0, b = 0, d = 0, sum = 0;
	int res[31];

	//input
	scanf("%d %d %d", &a, &b, &d);
	sum = a + b;
	//binary convert
	int count = 0;
	do{
		res[count++] = sum % d;
		sum /= d;
	}while(sum != 0);

	//output
	for(int i = count - 1; i >= 0; --i)
		printf("%d", res[i]);

	return 0;
}
