#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

struct Compare{
    bool operator()(std::tuple<int,int,int,int> a, std::tuple<int,int,int,int> b){
        if( std::get<3>(a)<std::get<3>(b) )
            return true;
        else if( std::get<3>(a)==std::get<3>(b) )
            if( std::get<1>(a)<std::get<1>(b) )
                return true;
            else if( std::get<1>(a)==std::get<1>(b) )
                return std::get<0>(a)<std::get<0>(b);
            else return false;
        else return false;
    }
};

int main()
{
    std::cout<<"\t----Priority Scheduling----\n\n";
    int n, time=0;
    std::cout<<"Enter the No. of Processes: ";
    std::cin>>n;
    std::vector<std::tuple<int,int,int,int>> pool(n);
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
    std::cout<<"Priority(1 is highest): ";
    for(int i=0;i<n;i++)
        std::cin>>std::get<3>(pool[i]);
    
    std::vector<std::tuple<int,int,int,int>> current;
    while(true)
    {
        for(auto it=pool.begin();it!=pool.end();it++)
            if(time >= std::get<1>(*it) && std::get<0>(*it)!=0)
            {
                current.push_back(*it);
                std::get<0>(*it) = 0;
            }
        
        std::stable_sort(current.begin(),current.end(), Compare());
        if(!current.empty())
        {
            std::get<2>(current[0])--;
            if(std::get<2>(current[0]) == 0)
            {
                CT[std::get<0>(current[0])-1] = time+1;
                current.erase(current.begin());
            }
        }
        time++;

        bool v = false;
        for(int i=0;i<n;i++)
            if(std::get<0>(pool[i]) != 0)
                v = v || true;
        v = v || !current.empty();
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