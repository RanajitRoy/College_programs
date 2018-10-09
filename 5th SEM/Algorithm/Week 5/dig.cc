#include <iostream>
#include <cmath>

int main()
{
	int s, d, smd=0;
	std::cout<<"Enter the sum and no. of digits: ";
	std::cin>>s>>d;
	if((double) s/d > 9)
	{
		std::cout<<"No number possible!!\n";
		return 1;
	}
	for(int i = 0; i < d; i++)
	{
		if(i == d-1)
		{
			smd = s*(int)pow(10, (double)i) + smd;
		}
		else if(s>9)
		{
			smd = 9*(int)pow(10, (double)i) + smd;
			s -= 9;
		}
		else{
			smd = (s-1)*(int)pow(10, (double)i) + smd;
			s = 1;
		}
	}
	std::cout<<"The minimum number possible: "<<smd<<"\n";
}