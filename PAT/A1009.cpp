#include <cstdio>

struct Poly
{
	int expo;		//exponents
	double coef;		//coefficients
} a[1010];

const int MAXN = 2000;

int main()
{

	int m, n, count = 0;		//polynomials nozeros terms
	double res[MAXN + 1] = {0.0};

	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d %lf", &a[i].expo, &a[i].coef);
	}

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		int expo;
		double coef;
		scanf("%d %lf", &expo, &coef);

		for(int j = 0; j < m; ++j)
			res[expo + a[j].expo] += (coef * a[j].coef);
	}

	for(int i = 0; i <= MAXN; ++i)
		if(res[i] != 0.0)
			++count;

	printf("%d", count);
	for(int i = MAXN; i >= 0; --i)
		if(res[i] != 0.0)
			printf(" %d %.1f", i, res[i]);
	
	return 0;
}
