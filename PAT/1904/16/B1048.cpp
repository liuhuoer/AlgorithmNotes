#include <cstdio>
#include <cstring>

void reserve(char* S)
{
    int len = strlen(S);
    char tmp;
    for(int i = 0; i < len / 2; ++i)
    {
        tmp = S[i];
        S[i] = S[len - i - 1];
        S[len - i - 1] = tmp;
    }
}

int main()
{
    char A[105], B[105];
    scanf("%s %s", &A, &B);
    int len_a = strlen(A);
    int len_b = strlen(B);
    int len = len_a > len_b ? len_a : len_b;
    reserve(A);
    reserve(B);
    char res[105] = {0};
    for(int tmp, num_a, num_b, i = 0; i < len; ++i)
    {
        num_a = i < len_a ? A[i] - '0' : 0;
        num_b = i < len_b ? B[i] - '0' : 0;
        //get single number 
        if(!(i % 2))
        {
            //even (odd(begin 0) = even(begin 1))
            tmp = (num_a + num_b) % 13;
            if(tmp == 10)
                res[i] = 'J';
            else if(tmp == 11)
                res[i] = 'Q';
            else if(tmp == 12)
                res[i] = 'K';
            else
                res[i] = tmp + '0';
        }
        else{
            //odd
	        tmp = num_b - num_a;
            if(tmp < 0)
                tmp += 10;
            res[i] = tmp + '0';
        }
    }
    reserve(res);
    puts(res);

    return 0;
}
