#include <cstdio>
#include <cstring>

const int weights[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
	char id[105][17];
	int z = 0, n, count = 0;

	scanf("%d", &n);
	for(int t = 0; t < n; ++t)
	{
		scanf("%s", id[t]);
		int i = 0;
		for(; i < 17; ++i)
		{
			if( !(id[t][i] >= '0' && id[t][i] <= '9') )
				break;
			z = (z + (id[t][i] - '0') * weights[i]) % 11;
		}
		if(i < 17)
			printf("%s\n", id[t]);
		else
		{
			if(check[z] != id[t][17])
				printf("%s\n", id[t]);
			else
				count++;
		}
	}

	if(count == n)
		printf("All passed");
	
	return 0;
}
