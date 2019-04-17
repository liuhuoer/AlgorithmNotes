#include <cstdio>

const char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
    //input 
    int input, sum;
    scanf("%d", &input);
    //get sum of all the digits of N
    sum = 0;
    do{
        sum += input % 10;
        input /= 10;
    }while(input);
    //output every digits of sum in english
    int sum_len = 0;
    int res[10];
    do{
        res[sum_len++] = sum % 10;
        sum /= 10;
    }while(sum);

    for(int i = sum_len - 1; i >= 0; --i)
    {
        printf("%s", num[res[i]]);
        if(i != 0)
            printf(" ");
    }

    return 0;
}