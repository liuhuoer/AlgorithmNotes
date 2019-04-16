#include <cstdio>
#include <cstring>

const char week[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	char str1[65], str2[65], str3[65], str4[65];
	//input
	scanf("%s\n%s\n%s\n%s", &str1, &str2, &str3, &str4);
	//compare first two string
	bool first = true;
	for(int i = 0; i < strlen(str1) && i < strlen(str2); ++i)
	{
		if(str1[i] == str2[i] && first == true)
		{
			if(str1[i] >= 'A' && str1[i] <= 'G')
			{
				printf("%s", week[str1[i] - 'A']);
				first = false;
			}
		}
		else if(str1[i] == str2[i] && first == false){
			if(str1[i] >= 'A' && str1[i] <= 'N') 
			{					
				printf(" %d", str1[i] - 'A' + 10);
				break;
			}
			else if(str1[i] >= '0' && str1[i] <= '9')
			{
				printf(" %d", str1[i] >= '0');
				break;
			}
		}
	}
	//compare next two string
	for(int i = 0; i < strlen(str3) && i < strlen(str4); ++i)
	{
		if(str3[i] == str4[i])
			if( (str3[i] >= 'a' && str3[i] <= 'z') ||
					(str3[i] >= 'A' && str3[i] <= 'Z'))
				printf(":%d", i);
	}

	return 0;
}
