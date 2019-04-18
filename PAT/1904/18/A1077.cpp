#include <cstdio>
#include <cstring>


void reserve(char* input)
{
	int len = strlen(input);
	for(int i = 0; i < len / 2; ++i)
	{
		int temp = input[i];
		input[i] = input[len - 1 - i];
		input[len - 1 - i] = temp;
	}
}

int main()
{
    char input[105][260];
	//input to n, char[][]
	int n;
	int mini_len = 260;
	scanf("%d", &n);
	getchar();	//deal with '\n'
	for(int i = 0; i < n; ++i)
	{
		//scanf("%s", &input[i]);
		gets(input[i]);
		//reserve
		reserve(input[i]);
		int len = strlen(input[i]);
		if(len < mini_len)
			mini_len = len;
	}
	//check diffierent with ever port after reserve
	int len_word = 0;
	for(int i = 0; i < mini_len; ++i)
	{
		int flag = true;
		char c = input[0][i];
		//compare this port in other n - 1 string 
		for(int j = 1; j < n; ++j)
		{
			if(c != input[j][i])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			++len_word;
	}
	if(len_word)
	{
		for(int i = len_word - 1; i >= 0; --i)
		{
			printf("%c", input[0][i]);
		}
	}
	else{
		printf("nai");
	}
	return 0;
}
