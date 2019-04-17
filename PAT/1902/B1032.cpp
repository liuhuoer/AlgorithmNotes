#include <cstdio>

const int MAXN = 10010;

int main()
{
	int m, num, grade, num_max = 1, grade_max = 0;
	int res[MAXN] = {0};
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d %d", &num, &grade);
		res[num] += grade;
		if(res[num] > grade_max)
		{
			num_max = num;
			grade_max = res[num];
		}
	}
	printf("%d %d", num_max, grade_max);
	return 0;
}
