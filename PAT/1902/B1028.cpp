#include <cstdio>

struct Age
{
	char name[10];
	int yy, mm, dd;
} temp, left, right, youngest, oldest;

bool more_equ(Age a, Age b)
{
	if(a.yy != b.yy)
		return a.yy >= b.yy;
	if(a.mm != b.mm)
		return a.mm >= b.mm;
	if(a.dd != b.dd)
		return a.dd >= b.dd;
}

bool less_equ(Age a, Age b)
{
	if(a.yy != b.yy)
		return a.yy <= b.yy;
	if(a.mm != b.mm)
		return a.mm <= b.mm;
	if(a.dd != b.dd)
		return a.dd <= b.dd;
}

void init()
{
	left.yy = youngest.yy = 1814;
	right.yy = oldest.yy = 2014;
	left.mm = right.mm = youngest.mm = oldest.mm = 9;
	left.dd = right.mm = youngest.mm = oldest.mm = 6;
}

int main()
{
	int m, count = 0;

	init();

	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%s %d/%d/%d", &temp.name, &temp.yy, &temp.mm, &temp.dd);

		if(more_equ(temp, left) && less_equ(temp, right))
		{
			if(less_equ(temp, oldest))
				oldest = temp;
			if(more_equ(temp, youngest))
				youngest = temp;
			++count;
		}
	}

	if(count == 0)
		printf("0\n");
	else
		printf("%d %s %s\n", count, oldest.name, youngest.name);

	return 0;
}
