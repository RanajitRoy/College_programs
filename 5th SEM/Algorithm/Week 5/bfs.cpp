#include <iostream>
#include <vector>
#include <list>
#include <queue>

int main()
{
    int v, e; std::cin>>v>>e;
    std::vector<std::list<int>> adjList(v);
	for(int i = 0; i < e; i++)
	{
		int x, y; std::cin>>x>>y;
		adjList[x].push_back(y);
	}
    std::vector<bool> visited(v,false);
    std::vector<int> depth(v,0);
    int start; std::cin>>start;
    std::queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        visited[x] = true;
        for(auto &i: adjList[x])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
                depth[i] = depth[x] + 1;
            }
        }
    }
    std::cout<<"Depth for each vertex:\n";
    for(auto i=0;i<v;i++)
    {
        std::cout<<i<<" -> "<<depth[i]<<"\n";
    }
}