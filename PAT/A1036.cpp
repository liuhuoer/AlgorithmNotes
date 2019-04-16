#include <cstdio>

struct People
{
	char name[15];
	char id[15];
	int grade;
}tmp, ans_f, ans_m;

void init()
{
	ans_f.grade = -1;
	ans_m.grade = 101;
}

int main()
{
	int m;
	char gender;
	
	init();
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%s %c %s %d", &tmp.name, &gender, &tmp.id, &tmp.grade);
		if(gender == 'F' && tmp.grade > ans_f.grade)
			ans_f = tmp;
		if(gender == 'M' && tmp.grade < ans_m.grade)
			ans_m = tmp;
	}

	if(ans_f.grade == -1)
		printf("Absent\n");
	else 
		printf("%s %s\n", ans_f.name, ans_f.id);

	if(ans_m.grade == 101)
		printf("Absent\n");
	else 
		printf("%s %s\n", ans_m.name, ans_m.id);

	if(ans_f.grade == -1 || ans_m.grade == 101)
		printf("NA\n");
	else 
		printf("%d\n", ans_f.grade - ans_m.grade);

	return 0;
}
