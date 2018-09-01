#include <iostream>
#include <vector>

int main()
{
	int n, coin_no;
	std::cout<<"Enter the no. of coin types: ";
	std::cin>>coin_no;
	std::vector<int> coins(coin_no);
	std::cout<<"Enter the coin types (space separated): ";
	for(auto &i: coins)
		std::cin>>i;
	std::cout<<"Enter the total change: ";
	std::cin>>n;
	std::vector<int> mem(n+1, 0);
	for(int i=1;i<=n;i++)
	{
		int minimum = (i<coins[0])? i : mem[i-coins[0]];
		for(int j=1;j<coin_no;j++)
			minimum = std::min(minimum, ((i<coins[j])? i : mem[i-coins[j]]));
		mem[i] = minimum+1;
	}
	std::cout<<"\nThe minimum no. of coins needed: "<<mem[n]<<std::endl;
}