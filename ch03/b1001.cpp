#include <cstdio>

int main()
{
	int i,step=0;
	scanf("%d",&i);
	for(step=0;i!=1;++step)
	{
		if(i&0x01)
			i=(3*i+1)/2;
		else
			i/=2;
	}
	printf("%d",step);
	return 0;
}
