#include <cstdio>
#include <algorithm>

const int MAXN = 100005;
using namespace std;

int main()
{
	int N = 0, K = 0, sum = 0, left = 0, right = 0;
	int twopoint[MAXN] = {0}, d[MAXN] = {0};

	//input to b[]
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &twopoint[i]);
		sum += twopoint[i];
		d[i] = sum;
	}
	
	scanf("%d", &K);
	//calculate
	for(int i = 1; i <= K; ++i)
	{
		//b[right] - b[left]
		scanf("%d%d", &left, &right);
		if(left > right) 
			swap(left, right);
		int result = d[right - 1] - d[left - 1];
		printf("%d\n", min(result, sum - result));
	}
	
	return 0;
}
