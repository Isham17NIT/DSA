class Solution {
public:
    int numberOfWays(string corridor) 
    {
        int mod=1e9+7;
        vector<pair<int,int>> partitions; //idx of 1st seat and 2nd seat of the resp partitions
        int prev=-1, numWays=1;
        for(int i=0;i<corridor.size();i++)
        {
            if(corridor[i]=='P')
                continue;
            else if(prev==-1)
                prev=i;
            else
            {
                partitions.push_back({prev,i});
                prev=-1;
            }
        }
        if(prev!=-1 || partitions.empty()) //odd number odd no. of seats or no seats at all
            return 0;
        for(int i=0;i<partitions.size()-1;i++)
        {
            int curr=partitions[i].second;
            int next=partitions[i+1].first;
            numWays=((long long)numWays*(long long)(next-curr))%mod;
        }
        return numWays;
    }
};