#include <cstdio>
#include <cstring>

int main()
{
	//input
	char input[85];
	gets(input);
	//partition and save in res[]
	char res[85][85];
	int num = 0;
	for(int i = 0, j = 0; i < strlen(input); ++i, ++j)
	{
		if(input[i] != ' ')
		{
			res[num][j] = input[i];
		}
		else{
			res[num][j] = '\0';
			j = -1;
			++num;
		}
	}
	//output
	for(int i = num; i >= 0; --i)
	{
		printf("%s", res[i]);
		if(i != 0)
			printf(" ");
	}

	return 0;
}
