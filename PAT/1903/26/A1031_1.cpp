#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() 
{
	/*
	char strs[100], res[40][40];
	//input
	gets(cin, strs);
	int N = strlen(strs);
	*/
    string strs;
	char res[40][40];

	//input
	getline(cin, strs);
	int N = strs.size();

	int n1 = (N + 2) / 3, n2 = N + 2 - 2 * n1;
	//init
	for(int i = 0; i < n1; ++i)
	{
		for(int j = 0; j < n2; ++j)
		{
			res[i][j] = ' ';
		}
	}
	int count = 0;
	//1st col
	for(int i = 0; i < n1; ++i)
	{
		res[i][0] = strs[count++];
	}
	//1st row
	for(int j = 1; j < n2; ++j)
	{
		res[n1 - 1][j] = strs[count++];
	}
	//2st col
	for(int i = n1 - 2; i >= 0; --i)
	{
		res[i][n2 - 1] = strs[count++];
	}
	//output
	for(int i = 0; i < n1; ++i)
	{
		for(int j = 0; j < n2; ++j)
			printf("%c", res[i][j]);
		printf("\n");
	}

	return 0;
}
