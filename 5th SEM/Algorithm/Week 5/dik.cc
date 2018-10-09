#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
struct compare
{
	bool operator()(const std::pair<int, int> x, const std::pair<int, int> y)
	{
		return x.second >= y.second;
	}
};
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
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> pq;
	std::cout<<"Enter the source and destination\n";
	int src; std::cin>>src;
	distance[src] = 0;
	pq.push(std::make_pair(src, 0));
	while(!pq.empty())
	{
		int temp = pq.top().first;
		pq.pop();
		for(auto& i : adjList[temp])
		{
			int v = i.first;
			if(distance[v] > distance[temp] + i.second)
			{
				distance[v] = distance[temp] + i.second;
				pq.push(std::make_pair(v, distance[v]));
			}
		}
	}
	std::cout<<"Shortest distances:\n";
	for(int i = 0; i < v; i++)
		std::cout<<src<<"->"<<i<<" = "<<distance[i]<<'\n';
}