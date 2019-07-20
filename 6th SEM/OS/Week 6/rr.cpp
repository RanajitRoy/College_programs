#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

struct Compare{
    bool operator()(std::tuple<int,int,int> a, std::tuple<int,int,int> b){
        if( std::get<1>(a)<std::get<1>(b) )
            return true;
        else if( std::get<1>(a)==std::get<1>(b) )
            return std::get<0>(a)<std::get<0>(b);
        else return false;
    }
};

int main()
{
    std::cout<<"\t----Round Robin Scheduling----\n\n";
    int n, time=0, rt=0, tq;
    std::cout<<"Enter the No. of Processes: ";
    std::cin>>n;
    std::vector<std::tuple<int,int,int>> pool(n);
    std::queue<std::tuple<int,int,int>> cur_q;
    std::vector<int> AT(n), CT(n), BT(n);
    std::cout<<"Arrival Time: ";
    for(int i=0;i<n;i++)
    {
        std::get<0>(pool[i]) = i+1;
        std::cin>>AT[i];
        std::get<1>(pool[i])=AT[i];
    }
    std::cout<<"Burst Time: ";
    for(int i=0;i<n;i++)
    {
        std::cin>>BT[i];
        std::get<2>(pool[i])=BT[i];
    }
    std::cout<<"Time Quantum: ";
    std::cin>>tq;
    std::stable_sort(pool.begin(), pool.end(), Compare());
    std::tuple<int,int,int> current;
    while(true)
    {
        for(auto it=pool.begin();it!=pool.end();it++)
            if(time >= std::get<1>(*it) && std::get<0>(*it)!=0)
            {
                cur_q.push(*it);
                std::get<0>(*it) = 0;
            }
        if(!cur_q.empty())
        {
            std::get<2>(cur_q.front())--;
            rt++;
            if(std::get<2>(cur_q.front()) == 0)
            {
                CT[std::get<0>(cur_q.front())-1] = time+1;
                cur_q.pop();
                rt=0;
            }
        }
        time++;
        if(rt==tq)
        {
            cur_q.push(cur_q.front());
            cur_q.pop();
            rt=0;
        }
        bool v = false;
        for(int i=0;i<n;i++)
            if(std::get<0>(pool[i]) != 0)
                v = v || true;
        v = v || !cur_q.empty();
        if(!v)
            break;
    }

    std::cout<<"\nPID\tArrival Time\tCompletion Time\tBurst Time\tWaiting Time\n";
    int avgWT=0, avgTAT=0;
    for(int i=0;i<n;i++)
    {
        avgWT+=CT[i]-AT[i]-BT[i];
        avgTAT+=CT[i]-AT[i];
        std::cout<<i+1<<"\t"<<AT[i]<<"\t\t"<<CT[i]<<"\t\t"<<BT[i]<<"\t\t"<<CT[i]-AT[i]-BT[i]<<"\n";
    }
    std::cout<<"\nAverage Waiting Time: "<<avgWT/n;
    std::cout<<"\n\nAverage Turn Around Time: "<<avgTAT/n<<"\n\n";
}