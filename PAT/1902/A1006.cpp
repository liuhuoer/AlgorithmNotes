#include <cstdio>

struct People
{
	char name[20];
	int hh, mm, ss;
} tmp, first, last;

void init()
{
	first.hh = 24;
	first.mm = first.ss = 60;
	last.hh = last.mm = last.ss = 0;
}

bool greater(People lhs, People rhs)
{
	if(lhs.hh != rhs.hh)
		return lhs.hh >= rhs.hh;
	else if(lhs.mm != rhs.mm)
		return lhs.mm >= rhs.mm;
	else 
		return lhs.ss >= rhs.ss;
}

int main()
{
	int m;

	init();
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%s %d:%d:%d", &tmp.name, &tmp.hh, &tmp.mm, &tmp.ss);
		if(greater(tmp, first) == false)
			first = tmp;


		scanf("%d:%d:%d", &tmp.hh, &tmp.mm, &tmp.ss);
		if(greater(tmp, last) == true)
			last = tmp;
	}

	printf("%s %s", first.name, last.name);

	return 0;
}
