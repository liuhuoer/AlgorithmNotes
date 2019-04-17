#include <cstdio>
#include <string>
using std::string;
int main()
{
	//init 1 array;?
	float a[1001] = {0};
	int n = 0;
	float temp = 0;
	//input 2 line;
	for(int i = 0; i <= 1; ++i)
	{
		scanf("%d", &n);
		for(int j = 0, k = 0; j < n; ++j)
		{
			scanf("%d%f", &k, &temp);
			a[k] += temp;
		}
	}
	//get count;
	int count = 0;
	for(int i = 0; i <= 1000; ++i)
		if(a[i] != 0)
			++count;

	//print;
	printf("%d", count);
	for(int i = 1000; i >= 0; --i)
	{
		if(a[i] != 0)
		{
			printf(" %d %.1f", i, a[i]);
		}
	}
	return 0;
}
