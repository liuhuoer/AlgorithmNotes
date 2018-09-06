#include <cstdio>

int P=2,len=10;

int main()
{
	//##base-P convert to base-10;
	//y=d1*P^(n-1)+d2*P^(n-2)+...+dn;
	int y=0;
	for(int product=1; x!=0; x/=P)
	{
		y+=(x%P)*product;
		product*=P;
	}

	//##base-10 convert to base-P;
	/*e.g.
	 * 11%2	=5...1;bottom
	 * 5%2	=2...1;
	 * 2%2	=1...0;
	 * 1%2	=0...1;top
	 * result 11 become 1011;
	 */
	//use do...while for y is sometime smaller than P;
	int a[50],num=0;
	do{
		a[num++]=y%P;
		y/=p;
	}while(y!=0)

	//##string to base-52;
	int id=0,s[10]={'a','b','c'};
	for(int i=0; i<len; ++i)
	{
		if(s[i]>='A'&&s[i]<='Z')
			id=id*52+(s[i]-'A');
		else if(s[i]>'a'&&s[i]<='z')
			id=id*52+(s[i]-'a')+26;
	}
	return 0;
}
