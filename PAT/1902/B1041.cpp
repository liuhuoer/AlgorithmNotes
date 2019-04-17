#include <cstdio>

const int MAXN = 1010;

struct Exam
{
	long long id;
	int exam_seat;
} exam[MAXN];

int main()
{
	int m, n, temp;

	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		long long  id;
		int seat, exam_seat;
		scanf("%lld %d %d", &id, &seat, &exam_seat);
		exam[seat].id = id;
		exam[seat].exam_seat = exam_seat;
	}

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		printf("%lld %d\n", exam[temp].id, exam[temp].exam_seat);
	}
	
	return 0;
}
