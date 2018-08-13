#include <iostream>
#include <vector>

template<typename T>
struct Matrix
{
	std::vector<std::vector<T>> mat;
	Matrix(int n, int m)
	{
		mat = std::vector<std::vector<T>>(n, std::vector<T>(m, 0));
	}
	void initialize()
	{
		for(auto &i: mat)
			for(auto &j: i)
				std::cin>>j;
	}
	void display()
	{
		for(auto &i: mat)
		{
			for(auto &j: i)
				std::cout<<"\t"<<j;
			std::cout<<std::endl;
		}
	}
	Matrix<T> operator+(Matrix<T> a)
	{
		Matrix<T> res(mat.size(), mat[0].size());
		
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<mat[i].size();j++)
				res.mat[i][j]=mat[i][j]+a.mat[i][j];
		return res;
	}
	Matrix<T> operator-(Matrix<T> a)
	{
		Matrix<T> res(mat.size(), mat[0].size());
		
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<mat[i].size();j++)
				res.mat[i][j]=mat[i][j]-a.mat[i][j];
		return res;
	}
	Matrix<T> operator*(Matrix<T> a)
	{
		Matrix<T> res(mat.size(), a.mat[0].size());
		
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<a.mat[0].size();j++)
				for(int k=0;k<mat[0].size();k++)
					res.mat[i][j]+=mat[i][k]*a.mat[k][j];
		return res;
	}
};

int main()
{
	std::cout<<"Enter the size of the matrices: ";
	int n,m;
	std::cin>>n>>m;
	Matrix<int> A(n, m), B(n, m), C(n, m), D(n, m);
	std::cout<<"Enter the matrix A: \n";
	A.initialize();
	std::cout<<"Enter the matrix B: \n";
	B.initialize();
	std::cout<<"Enter the matrix C: \n";
	C.initialize();
	D = A+B*C;
	std::cout<<"D=A+B*C then D:\n";
	D.display();
	std::cout<<std::endl;
	return 0;
}
