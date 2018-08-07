#include <iostream>
#include <vector>

#define MAX 100

class Stack
{
	std::vector<int> stk;
	public:
	void push(int elm)
	{
		if(MAX == stk.size())
			std::cout<<"stack overflow\n";
		else stk.push_back(elm);
	}
	void pop()
	{
		if(stk.size()==0)
			std::cout<<"\rstack underflow\n";
		else{
			std::cout<<"\r"<<stk[stk.size()-1]<<" is popped\n";
			stk.pop_back();
		}
	}
	void display()
	{
		if(stk.size()==0)
			std::cout<<"\rempty stack\n";
		else{
			std::cout<<"\rStack elements:";
			for(int i=0;i<stk.size();i++)
				std::cout<<" "<<stk[i]<<",";
			std::cout<<"\n";
		}
	}
	void display_top()
	{
		if(stk.size()==0)
			std::cout<<"\rempty stack\n";
		else{
			std::cout<<"\rStack top element is = "<<stk[stk.size()-1]<<"\n";
		}
	}
	void empty()
	{
		if(stk.size()==0)
			std::cout<<"\rEmpty!\n";
		else std::cout<<"\rNot empty! Stack size is = "<<stk.size()<<"\n";
	}
};

int main()
{
	int com, flag=0, elm;
	Stack st;
	std::cout<<"Commands:\n"<<" 1: push\n"<<" 2: pop\n"<<" 3: display stack\n"<<" 4: check empty\n"<<" 5: display top element\n"<<" 6: exit\n";
	do
	{
		std::cout<<"Enter the command: ";
		std::cin>>com;
		switch(com)
		{
			case 1:	std::cout<<"\rEnter the element: ";
					std::cin>>elm;
					st.push(elm);
					break;
			case 2: st.pop(); break;
			case 3: st.display(); break;
			case 4: st.empty(); break;
			case 5: st.display_top(); break;
			case 6: flag=1; break;
			default: std::cout<<"\rinvalid command!!\n";
		}
	}while(flag!=1);
	return 0;
}
