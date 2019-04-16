#include <cstdio>
#include <cstring>

int main()
{
	int count[10] = {0};
	//input
	char str[1000];
	gets(str);
	//count
	for(int i = 0; i < strlen(str); ++i)
	{
		++count[str[i] - '0'];
	}
	//output
	for(int i = 0; i <= 9; ++i)
		if(count[i] != 0)
			printf("%d:%d\n", i, count[i]);
	
	return 0;
}
