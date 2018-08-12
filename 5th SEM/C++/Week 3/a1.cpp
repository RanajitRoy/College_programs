#include <iostream>
#include <vector>

template <typename T>
bool search(std::vector<T>& vect, T& elm)
{
	int low=0, high=vect.size(), mid;
	while(low<high-1)
	{
		mid=(low+high)/2;
		if(vect[mid]==elm)
			return true;
		else if(vect[mid]<elm)
			low = mid;
		else high = mid;
	}
	if(low==high-1)
		if(vect[mid]==elm)
			return true;
		else return false;
}

int main()
{
	int n, in;
	std::cout<<"enter the size of both vector\n";
	std::cin>> n;
	std::vector<int> vect1(n);
	std::vector<std::string> vect2(n);
	std::cout<<"Enter int vector\n";
	for(auto &i: vect1)
		std::cin>>i;
	std::cout<<"Enter the element\n";
	std::cin>>in;
	if(search(vect1, in))
		std::cout<<"Found in int vector\n";
	else std::cout<<"Not found in int vector\n";
	std::cout<<"Enter string vector\n";
	for(auto &i: vect2)
		std::cin>>i;
	std::string str;
	std::cout<<"Enter the element\n";
	std::cin>>str;
	if(search(vect2, str))
		std::cout<<"Found in string vector\n";
	else std::cout<<"Not found in string vector\n";
	return 0;
}