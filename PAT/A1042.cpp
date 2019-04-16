#include <cstdio>

const int N = 54;
char map[5] = {'S', 'H', 'C', 'D', 'J'};

int main()
{
	int start[N + 1], end[N + 1], order[N + 1];
	int k;

	scanf("%d", &k);
	//init start[]
	for(int i = 1; i <= N; ++i)
		start[i] = i;
	//read order[]
	for(int i = 1; i <= N; ++i)
		scanf("%d", &order[i]);

	//sort the start[]
	for(int t = 0; t < k; ++t)
	{
		for(int i = 1; i <= N; ++i)
			end[order[i]] = start[i];
		for(int i = 1; i <= N; ++i)
			start[i] = end[i];
	}

	//output end[]
	for(int i = 1; i <= N; ++i)
	{
		if(i != 1) 
			printf(" ");
		printf("%c%d", map[(end[i] - 1) /13], (end[i] - 1) % 13 + 1);
	}

	return 0;
}
