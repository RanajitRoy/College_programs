#include <iostream>
#include <vector>

struct Co_class
{
	int x, y, z;
	Co_class(int n1, int n2, int n3)
	{
		x=n1;
		y=n2;
		z=n3; 
	}
	Co_class operator+(Co_class &a)
	{
		return Co_class(x+a.x, y+a.y, z+a.z);
	}
	Co_class operator-(Co_class &a)
	{
		return Co_class(x-a.x, y-a.y, z-a.z);
	}
};

int main()
{
	Co_class co1(1,2,3);
	Co_class co2(1,2,3);
	Co_class res = co1 + co2;
	std::cout<<res.x<<" "<<res.y<<" "<<res.z<<"\n";
	res = co1 - co2;
	std::cout<<res.x<<" "<<res.y<<" "<<res.z<<"\n";
	return 0;
}