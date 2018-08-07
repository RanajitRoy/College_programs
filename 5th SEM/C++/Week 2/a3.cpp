#include<iostream>

class Complex
{
	public:
		int real,img;
		Complex()
		{
			real=0;
			img=0;
		}
		Complex(int n1)
		{
			real=n1;
			img=n1;
		}
		Complex(int n1, int n2)
		{
			real=n1;
			img=n2;
		}
		Complex add(Complex &a,Complex &b)
		{
			Complex temp;
			temp.real=b.real+a.real;
			temp.img=b.img+a.img;
			return temp;
		}
};

int main()
{
	int n, m;
	std::cout<<"Enter the real part of the complex number: ";
	std::cin>>n;
	std::cout<<"Enter the imaginary part of the complex number: ";
	std::cin>>m;
	Complex ob1(n,m);
	std::cout<<"Enter value of the complex number parts: ";
	std::cin>>n;
	Complex ob2(n);
	Complex ob3;
	ob3=ob3.add(ob1,ob2);
	std::cout<<"The resultant complex number is: "<<ob3.real<<((ob3.img<0)?"-i":"+i")<<-ob3.img<<"\n";
	return 0;
}
