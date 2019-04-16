#include <cstdio>

const char dic[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

int main()
{
	int a1, b1, c1;
	scanf("%d %d %d", &a1, &b1, &c1);
	printf("#%c%c%c%c%c%c", dic[a1 / 13], dic[a1 % 13], dic[b1 / 13], dic[b1 % 13], dic[c1 / 13], dic[c1 % 13]);
	
	return 0;
}
