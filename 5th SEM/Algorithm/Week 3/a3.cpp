#include <iostream>
#include <vector>

int main()
{
	int n, card;
	std::cout<<"Enter cardinality of the set: ";
	std::cin>>card;
	std::vector<int> set(card);
	std::cout<<"Enter elements of the set: ";
	for(auto &i: set)
		std::cin>>i;
	std::cout<<"Enter the sum: ";
	std::cin>>n;
	std::vector<std::vector<bool>> mem(n+1, std::vector<bool>(card+1));
	for(auto &i: mem)
		i[0] = false;
	mem[0] = std::vector<bool>(card+1, true);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=card;j++)
		{
			mem[i][j] = mem[i][j-1] || ((i<set[j-1])? false : mem[i-set[j-1]][j-1]);
		}
	}
	std::cout<<"\nResult: ";
	if(mem[n][card]==true)
		std::cout<<"sum is possible"<<std::endl;
	else std::cout<<"sum is not possible"<<std::endl;
}