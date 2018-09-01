#include <iostream>
#include <vector>

int main()
{
	int m, n, minimum;
	std::cout<<"Enter the size of Matrix: ";
	std::cin>>m>>n;
	std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
	std::cout<<"Enter the Matrix:"<<std::endl;
	for(auto &i: matrix)
		for(auto &j: i)
			std::cin>>j;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(i == 0)
			{
				if(j == 0)
					minimum = 0;
				else minimum = matrix[i][j-1];
			}
			else{
				if(j == 0)
					minimum = matrix[i-1][j];
				else minimum = std::min(matrix[i-1][j-1], std::min(matrix[i][j-1],matrix[i-1][j]));
			}
			matrix[i][j] += minimum;
		}
	std::cout<<"\nThe minimum cost = "<<matrix[m-1][n-1]<<std::endl;
}