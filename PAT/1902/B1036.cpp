#include <cstdio>

int main()
{
	int row, col;
	char k;

	scanf("%d %c", &col, &k);

	if(col % 2 == 1)
		row = col / 2 + 1;
	else
		row = col / 2;

	for(int j = 0; j < col; ++j)
		printf("%c", k);

	printf("\n");
	for(int i = 2; i < row; ++i)
	{
		printf("%c", k);
		for(int j = 2; j < col; ++j)
			printf(" ");
		printf("%c", k);
	}

	printf("\n");
	for(int j = 0; j < col; ++j)
		printf("%c", k);

	return 0;
}
