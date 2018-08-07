#include <iostream>
using namespace std;
int main()
{
	int m,n,temp;
	cout<<"Enter the two numbers :";
	cin>>m>>n;
	int& a=m;
	int& b=n;
	temp=b;
	b=a;
	a=temp;
	cout<<"m="<<m<<"n="<<n;
	return 0;
}
