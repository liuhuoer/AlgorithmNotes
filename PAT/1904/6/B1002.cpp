#include <cstdio>
#include <cstring>

const char n[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
	char input[100];
	//input
	gets(input);
	//sum
	int sum = 0;
	for(int i = 0; i < strlen(input); ++i)
		sum += input[i] - '0';
	//every place
	int num = 0;
	int res[10];
	do{
		res[num++] = sum % 10;
		sum /= 10;
	}while(sum != 0);
	//output
	for(int i = num - 1; i >= 0; --i)
	{
		printf("%s", n[res[i]]);
		if(num != 0)
			printf(" ");
	}

	return 0;
}
