#include <cstdio>

const char c_num[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    int input;
    scanf("%d", &input);
    //'-'
    if(input < 0)
    {
        printf("Fu ");
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
    int count = 0;
    for(int i = num - 1; i >= 0; --i)
    {
        if(port_input[i] != 0)
        {
            //if( (port_input[i + 1] == 0) && (i != num -1))    // error:
            // #add for 100001234
            if( (port_input[i + 1] == 0) && (i != num -1) && (i % 4 != 3))
            {
                //if former port is 0, output 0 and port_input[i]
                printf(" ling");
            }else if(count == 4){   // #add for 100001234
                printf(" ling");
                count = 0;
            }
            printf("%s%s", i != num -1? " " : "", c_num[port_input[i]]);

            //"qian", "bai", "shi" in four ports
            if(i % 4 == 3)
                printf(" Qian");
            else if(i % 4 == 2)
                printf(" Bai");
            else if(i % 4 == 1)
                printf(" Shi");
        }else if(num - 1 == 0 && port_input[i] == 0){       // #add for 0
            printf("ling");
        }else{      // #add for 100001234
            if(port_input[i + 1] != 0)
            {
                count = 0;
            }
            ++count;
        }
        //if "shi", "bai", "qian" ports = 0, output 0

        if(i % 4 == 0)
        {
            //"wan", "yi"
            if(i / 4 == 2 && count != 4)
                printf(" Yi");
            else if(i / 4 == 1 && count != 4)
                printf(" Wan");
        }
    }
}

/*
# test case1:
-123456789

# test result1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu

# test case2:
100800

# test result2:
yi Shi Wan ling ba Bai

# test case3:
-10301234

# test result3:
Fu yi Qian ling san Shi Wan yi Qian er Bai san Shi si

*/