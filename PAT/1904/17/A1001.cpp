#include <cstdio>

int main()
{
    //input
    int A, B;
    scanf("%d %d", &A, &B);
    //A+B
    int sum;
    sum = A + B;
    //'-'
    if(sum < 0)
    {
        printf("-");
        sum = -sum;
    }
    //int2string
    int res[10];
    int num = 0;
    do{
        res[num++] = sum % 10;
        sum /= 10;
    }while(sum);
    //output
    for(int i = num - 1; i >= 0; --i)
    {
        printf("%d", res[i]);
        if(i > 0 && i % 3 == 0)
            printf(",");
    }

    return 0;
}
