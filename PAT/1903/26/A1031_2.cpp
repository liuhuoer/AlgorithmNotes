#include <cstdio>
#include <cstring>

int main() 
{
	char strs[100], res[100];
	
	gets(strs);
	int N = strlen(strs);
	int n1 = (N + 2) / 3, n2 = N + 2 - 2 * n1;
	//1st row ~ (n1-1)st row
	for(int i = 0; i < n1 - 1; ++i)
	{
		printf("%c", strs[i]);
		res[i] = strs[i];
		for(int j = 0; j < n2 - 2; ++j)
		{
			printf(" ");
		}
		printf("%c\n", strs[N - i - 1]);
	}
	//2st col
	for(int i = 0; i < n2; ++i)
	{
		printf("%c", strs[n1 + i]);
	}

	return 0;
}
