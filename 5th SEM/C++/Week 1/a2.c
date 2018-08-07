#include<iostream>
using namespace std;
double calc(int& c,int& d)
{
	int centi,ft,inc;
	double conv;
	ft=c;
	inc=d;
	conv=(ft*12)+inc;
	centi=2.54*conv;
	return centi;
}

int main()
{
	int ft,inc;
	double value;
	cout<<"Enter length in foot :";
	cin>>ft;
	cout<<"\nEnter length in inches :";
	cin>>inc;
	value=calc(ft,inc);
	cout<<"\nCentimeter ="<<value;
}
