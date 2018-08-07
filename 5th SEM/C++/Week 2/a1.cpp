#include <iostream>
#include <string>

template <typename T>

void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	std::string str1 = "Ranajit", str2 = "Roy";
	int a=11, b=12;
	double d1 = 3.2, d2= 6.9;
	char c1='A', c2='B';
	std::cout<<"str1="<<str1<<" str2="<<str2<<std::endl;
	std::cout<<"a="<<a<<" b="<<b<<std::endl;
	std::cout<<"d1="<<d1<<" d2="<<d2<<std::endl;
	std::cout<<"c1="<<c1<<" c2="<<c2<<std::endl;
	std::cout<<"\nAfter swapping:\n";
	swap(str1, str2);
	std::cout<<"str1="<<str1<<" str2="<<str2<<std::endl;
	swap(a, b);
	std::cout<<"a="<<a<<" b="<<b<<std::endl;
	swap(d1, d2);
	std::cout<<"d1="<<d1<<" d2="<<d2<<std::endl;
	swap(c1, c2);
	std::cout<<"c1="<<c1<<" c2="<<c2<<std::endl;
	return 0;
}
