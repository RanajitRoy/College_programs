#include <iostream>
#include <vector>

template<typename T>
class Matrix
{
	std::vector<std::vector<T>> &mat;
	mat(int n, int m)
	{
		mat = std::vector<std::vector<T>>(n, std::vector<T>(m));
	}
public:
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
			std::endl;
		}
	}
	Matrix<T> operator+(Matrix<T> &a)
	{
		Matrix<T> res(mat.size(), mat[0].size());
		
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<mat[i].size();j++)
				res[i][j]=mat[i][j]+a[i][j];
		return res;
	}
	Matrix<T> operator-(Matrix<T> &a)
	{
		Matrix<T> res(mat.size(), mat[0].size());
		
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<mat[i].size();j++)
				res[i][j]=mat[i][j]-a[i][j];
		return res;
	}
	Matrix<T> operator*(Matrix<T> &a)
	{
		Matrix<T> res(mat.size(), a[0].size());
		
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<a[0].size();j++)
				for(int k=0;k<mat[0].size();k++)
					res[i][j]=mat[i][k]+a[k][j];
		return res;
	}
};

int main()
{
	std::cout<<"Enter the size of the matrices: ";
	int n,m;
	std::cin>>n>>m;
	Matrix<int> A(n, m), B(n, m);
	Matrix<double> C(n, m), D(n, m);
	A.initialize();
	B.initialize();
	C.initialize();
	D.initialize();
	(A+B).display()
	(A-B).display();
	(A*B).display();
	(C+D).display()
	(C-D).display();
	(D*C).display();
	return 0;
}
