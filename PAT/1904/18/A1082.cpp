#include <cstdio>

const char c_num[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    int input;
    scanf("%d", &input);
    //'-'
    if(input < 0)
    {
        printf("fu ");
        input = -input;
    }
    //read num to int port_input[]
    int num = 0;
    int port_input[10] = {0};
    do{
        port_input[num++] = input % 10;
        input /= 10;
    }while(input);

    //output
    for(int i = num - 1; i >= 0; --i)
    {
        if(port_input[i] != 0)
        {
            if( (port_input[i + 1] == 0) && (i != num -1))
            {
                //if former port is 0, output 0 and port_input[i]
                printf(" ling");
            }
            printf("%s%s", i != num -1? " " : "", c_num[port_input[i]]);

            //"qian", "bai", "shi" in four ports
            if(i % 4 == 3)
                printf(" Qian");
            else if(i % 4 == 2)
                printf(" Bai");
            else if(i % 4 == 1)
                printf(" Shi");
        }
        //if "shi", "bai", "qian" ports = 0, output 0

        if(i % 4 == 0)
        {
            //"wan", "yi"
            if(i / 4 == 2)
                printf(" Yi");
            else if(i / 4 == 1)
                printf(" Wan");
        }
    }
}