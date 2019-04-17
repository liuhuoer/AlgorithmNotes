#include <cstdio>

const char WTL[3] = {'W','T','L'};

int main()
{
	int max = 0, idx = 0;
	float tmp, val, ans = 1.0;

	for(int i = 0; i < 3; ++i)	
	{
		tmp = 0.0;
		for(int j = 0; j < 3; ++j)
		{
			scanf("%f", &val);
			if(val > tmp)
			{
				idx = j;
				tmp = val;
			}
		}
		ans *= tmp;
		printf("%c ", WTL[idx]);
	}

	printf("%.2f", (ans * 0.65 - 1) * 2);

	return 0;
}
