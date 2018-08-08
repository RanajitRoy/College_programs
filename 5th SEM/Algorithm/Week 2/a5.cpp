#include <iostream>
#include <vector>
#include <tuple>

typedef std::vector<std::vector<int>> data;

data merge(const data &a, const data &b, const data &c, const data &d)
{
	int n = a.size()*2;
	data res(n, std::vector<int>(n,0));
	
	for(int i = 0, x = 0; i < n/2; i++, x++)
		for(int j = 0, y = 0; j < n/2; j++, y++)
			res[i][j] = a[x][y];

	for(int i = 0, x = 0; i < n/2; i++, x++)
		for(int j = n/2, y = 0; j < n; j++, y++)
			res[i][j] = b[x][y];
	
	for(int i = n/2, x = 0; i < n; i++, x++)
		for(int j = 0, y = 0; j < n/2; j++, y++)
			res[i][j] = c[x][y];
	
	for(int i = n/2, x = 0; i < n; i++, x++)
		for(int j = n/2, y = 0; j < n; j++, y++)
			res[i][j] = d[x][y];
	return res;
}

std::tuple<data, data, data, data> slice(const std::vector<std::vector<int>> &mat)
{
	int n = mat.size();
	std::vector<std::vector<int>> ans1(n/2, std::vector<int>(n/2));
	std::vector<std::vector<int>> ans2(n/2, std::vector<int>(n/2));
	std::vector<std::vector<int>> ans3(n/2, std::vector<int>(n/2));
	std::vector<std::vector<int>> ans4(n/2, std::vector<int>(n/2));
	for(int i = 0; i < n/2; i++)
		for(int j = 0; j < n/2; j++)
			ans1[i][j] = mat[i][j];

	for(int i = 0, x = 0; i < n/2; i++, x++)
		for(int j = n/2, y = 0; j < n; j++, y++)
			ans2[x][y] = mat[i][j];

	for(int i = n/2, x = 0; i < n; i++, x++)
		for(int j = 0, y = 0; j < n/2; j++, y++)
			ans3[x][y] = mat[i][j];

	for(int i = n/2, x = 0; i < n; i++, x++)
		for(int j = n/2, y = 0; j < n; j++, y++)
			ans4[x][y] = mat[i][j];
	return std::make_tuple(ans1, ans2, ans3, ans4);
}

data operator-(const data& a, const data& b)
{
	std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size())); 
	for(int i=0;i<a.size();i++)
		for(int j=0;j<a.size();j++)
			c[i][j]=a[i][j]-b[i][j];
	return c;
}

data operator+(const data& a, const data& b)
{
	std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size())); 
	for(int i=0;i<a.size();i++)
		for(int j=0;j<a.size();j++)
			c[i][j]=a[i][j]+b[i][j];
	return c;
}

data product(data X, data Y)
{
	int n = X.size();
	if(n==2)
	{
		data bound(2,std::vector<int>(2));
		bound[0][0] = (X[0][0]*Y[0][0])+(X[0][1]*Y[1][0]);
		bound[0][1] = (X[0][0]*Y[0][1])+(X[0][1]*Y[1][1]);
		bound[1][0] = (X[1][0]*Y[0][0])+(X[1][1]*Y[1][0]);
		bound[1][1] = (X[1][0]*Y[0][1])+(X[1][1]*Y[1][1]);
		return bound;
	}
	if(n%2==1)
	{
		for(int i=0;i<X.size();i++)
		{
			X[i].push_back(0);
			Y[i].push_back(0);
		}
		X.push_back(std::vector<int>(X.size(),0));
		Y.push_back(std::vector<int>(Y.size(),0));
		Y[Y.size()-1][Y.size()-1]=1;
		X[X.size()-1][X.size()-1]=1;
	}
	data A, B, C, D, E, F, G, H;
	std::tie(A, B, C, D) = slice(X);
	std::tie(E, F, G, H) = slice(Y);
	data P1 = product(A, F-H);
	data P2 = product(A+B, H);
	data P3 = product(C+D, E);
	data P4 = product(D, G-E);
	data P5 = product(A+D, E+H);
	data P6 = product(B-D, G+H);
	data P7 = product(A-C, E+F);
	auto temp = merge((P6+P5)+(P4-P2), P1+P2, P3+P4, (P1+P5)-(P3+P7));
	if(n%2==1)
	{
		temp.pop_back();
		for(auto& i: temp)
			i.pop_back();
	}
	return temp;
}

int main()
{
	int n;
	std::cout<<"Enter n: ";
	std::cin>>n;
	data mtx1(n, std::vector<int>(n)), mtx2(n, std::vector<int>(n));
	std::cout<<"Enter the 1st matrix:\n";
	for(auto& i : mtx1)
		for(auto& j : i)
			std::cin>>j;
	std::cout<<"Enter the 2st matrix:\n";
	for(auto& i : mtx2)
		for(auto& j : i)
			std::cin>>j;
	std::cout<<"The resultant matrix:\n";
	auto res = product(mtx1,mtx2);
	for(auto& i : res)
	{
		for(auto& j : i)
			std::cout<<j<<", ";
		std::cout<<"\n";
	}
	std::cout<<std::endl;
	return 0;
}
