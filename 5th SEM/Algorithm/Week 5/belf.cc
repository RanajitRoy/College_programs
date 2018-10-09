#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

int main()
{
	int e, v; std::cin>>v>>e;
	std::vector<std::list<std::pair<int, int>>> adjList(v);
	int inf = 1;
	for(int i = 0; i < e; i++)
	{
		int x, y, z; std::cin>>x>>y>>z;
		adjList[x].push_back(std::make_pair(y, z));
		inf += z;
	}
	std::vector<int> distance(v, inf);
	int src; std::cin>>src;
	distance[src] = 0;
	for(int i = 0;i < v-1; i++)
	{
		std::vector<int> temp(distance);
        for(auto j=0;j<v;j++)
        {
            for(auto k = adjList[j].begin();k!=adjList[j].end();k++)
            {
                if(distance[k->first] > distance[j]+k->second)
                {
                    temp[k->first] = distance[j] + k->second;
                }
            }
        }
        distance = temp;
	}
	std::cout<<"Shortest distances:\n";
	for(int i = 0; i < v; i++)
		std::cout<<src<<"->"<<i<<" = "<<distance[i]<<'\n';
}