//将字符串全部转换为小写
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using std::cout;using std::cin;using std::string;
int main()
{
	string str;
	cin>>str;
	transform(str.begin(),str.end(),str.begin(),tolower);
	cout<<str<<std::endl;
	transform(str.begin(),str.end(),str.begin(),toupper);
	cout<<str;
	 
	return 0;
}
