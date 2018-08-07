#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	stringstream ss(str);
	while(ss>>str)
	{
		reverse(str.begin(), str.end());
		cout<<str<<" ";
	}
}
