#include <cstdio>
#include <cstdlib>

int main()
{
  int a=0,b=0,sum=0,sum_abs=0;
  scanf("%d %d",&a,&b);
  sum_abs=abs(a+b);
  sum=a+b;
  
  if(sum_abs<1000)
    printf("%d",sum);
  else if(sum_abs<1000000)
    printf("%d,%03d",sum/1000,sum_abs%1000);
  else if(sum_abs>=1000000)
    printf("%d,%03d,%03d",sum/1000000,(sum_abs/1000)%1000,sum_abs%1000);

  return 0;
}
