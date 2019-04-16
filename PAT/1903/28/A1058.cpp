#include <cstdio>

const int Gal = 29, Sic = 17;

int main()
{
	int a1, b1, c1, a2, b2, c2, a, b, c;
	
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	c = (c1 + c2) % Gal;
	int inc = (c1 + c2) / Gal;
	b = (b1 + b2 + inc) % Sic;
	inc = (b1 + b2) / Sic;
	a = a1 + a2 + inc;

	printf("%d.%d.%d", a, b, c);
	
	return 0;
}
