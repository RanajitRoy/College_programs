#include <iostream>
#include <vector>

void preprocess(std::string &pat, std::vector<int> &vect)
{
	vect[0]=0;
	int i=1, j=0, n = pat.length();
	while(n>i)
	{
		if(pat[j] == pat[i])
		{
			vect[i] = j+1;
			i++; j++;
		}
		else{
			if(j>0)
				j = vect[j-1];
			else{
				vect[i] = 0;
				i++;
			}
		}
	}
}

void kmp(std::string &str, std::string &pat)
{
	int i=0, j=0, n=str.length();
	std::vector<int> lps(pat.length(), 0);
	preprocess(pat, lps);
	std::cout<<"The locations of the pattern: ";
	while(i<n)
	{
		if(pat[j] == str[i])
		{
			if(j == pat.length()-1)
			{
				std::cout<<i-pat.length()+1<<" ";
				j = lps[j];
				i++;
			}
			else{
				i++; j++;
			}
		}
		else
		{
			if(j == 0)
				i++;
			else{
				j = lps[j-1];
			}
		}
	}
	std::cout<<std::endl;
}

int main()
{
	std::string str, pat;
	std::cout<<"Enter the String: ";
	std::cin>>str;
	std::cout<<"Enter the pattern: ";
	std::cin>>pat;
	kmp(str, pat);
}