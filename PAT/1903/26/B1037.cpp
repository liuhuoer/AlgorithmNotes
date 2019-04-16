#include <cstdio>

const int Gal  = 17 * 29;
const int Sic = 17;

int main()
{
	int a1, b1, c1, a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int prices = a1 * Gal + b1 * Sic + c1;
	int money = a2 * Gal + b2 * Sic + c2;

	int res = money - prices;
	if(res < 0)
	{
		printf("-");
		res = -res;
	}
	printf("%d.%d.%d", res / Gal, (res % Gal) / Sic, res % Sic);

	return 0;
}
