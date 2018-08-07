#include<iostream>
using namespace std;
class Rectangle
{
public:
	float length,width,peri,ar;
	void setlength(float l)
	{
		length=l;
	}
	void setwidth(float w)
	{
		width=w;
	}
	float perimeter()
	{
		peri=2*(length+width);
		return peri;
	}
	float area()
	{
		ar=length*width;
		return ar;
	}
	void show()
	{
		cout<<"Length="<<length<<"\n";
		cout<<"width="<<width<<"\n";
	}
	int sameArea(Rectangle r)
	{
		if(area()==r.area())
			return 1;
		else return 0;
	}
};
int main()
{
	float len,wid,len2,wid2;
	cout<<"Enter the length(1st rectangle) :";
	cin>>len;
	cout<<"Enter the width(1st rectangle) :";
	cin>>wid;
	Rectangle rec1,rec2;
	rec1.setlength(len);
	rec1.setwidth(wid);
	cout<<"Enter the length(2nd rectangle) :";
	cin>>len2;
	cout<<"Enter the width(2nd rectangle) :";
	cin>>wid2;
	rec2.setlength(len2);
	rec2.setwidth(wid2);
	cout<<"1st rectangle : \n Area="<<rec1.area()<<"Perimeter ="<<rec1.perimeter()<<"\n";
	cout<<"2nd rectangle : \n Area="<<rec2.area()<<"Perimeter ="<<rec2.perimeter()<<"\n";
	cout<<"\n Are both areas same? : if yes 1 else 0 :\n"<<rec1.sameArea(rec2);
}
