#include <cstdio>

int main()
{
	int t, count = 0;
	scanf("%d", &t);
	//overflow，longlong range is [-2^63, 2^63)
	for(;t > 0; --t)
	{
		long long a, b, c, res;
		bool flag = false;
		//input
		scanf("%lld%lld%lld", &a, &b, &c);
		res = a + b;
		//over upper bound [2^63, 2^64 - 2] ==> [-2^63, -2]
		if(a > 0 && b > 0 && res < 0)
			flag = true;
		//over lower bound [-2^64, -2^63 - 1] ==> [0, 2^63 - 1]
		else if(a < 0 && b < 0 && res >= 0)
			flag = false;
		else if(res > c)
			flag = true;
		else 
			flag = false;
		//output
		if(flag)
			printf("Case #%d: true\n", ++count);
		else
			printf("Case #%d: false\n", ++count);
	}
	return 0;
}
