#include <cstdio>

const int MAXN = 1010;

struct student
{
	char name[15];
	char id[15];
	int grade;
} anx_max, anx_min, temp;

int main()
{
	int m;
	scanf("%d", &m);
	anx_max.grade = -1;
	anx_min.grade = 101;
	for(int i = 0; i < m; ++i)
	{
		scanf("%s %s %d", &temp.name, &temp.id, &temp.grade);
		if(temp.grade > anx_max.grade)
			anx_max = temp;
		if(temp.grade < anx_min.grade)
			anx_min = temp;
	}
	
	printf("%s %s\n", anx_max.name, anx_max.id);
	printf("%s %s\n", anx_min.name, anx_min.id);

	return 0;
}
