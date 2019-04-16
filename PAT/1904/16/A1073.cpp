#include <cstdio>
#include <cstring>

int main()
{
	//input
	char input[10010];
	gets(input);
	//get position of E
	int len = strlen(input);
	int pos = 0;
	for(int i = 0; i < len; ++i)
	{
		if(input[i] == 'E')
			pos = i;
	}
	//'+' or '-'
	if(input[0] == '-')
		printf("-");
	//calculate the exponent
	int exp = 0;
	for(int i = pos + 2; i < len; ++i)
	{
		exp = exp * 10 + input[i] - '0';
	}
	//if exponent == 0
	if(exp == 0)
		for(int i = 1; i < pos; ++i)
			printf("%s", input[i]);
	//calculate position of point and output
	if(input[pos + 1] == '-')
	{
		printf("0.");
		for(int i = 0; i < exp - 1; ++i)
		{
			printf("0");
		}
		printf("%c", input[1]);
		for(int i = 3; i < pos; ++i)
		{
			printf("%c", input[i]);
		}
	}else {
		for(int i = 1; i < pos; ++i)
		{
			if(input[i] == '.')
				continue;
			printf("%c", input[i]);
			//pos - 3 != exp
			if(exp == i - 2 && exp != pos - 3)
				printf(".");
		}
		for(int i = 0; i < exp - (pos - 3); ++i)
			printf("0");
	}

	return 0;
}
