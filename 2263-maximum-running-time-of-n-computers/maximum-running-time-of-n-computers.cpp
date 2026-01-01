class Solution 
{
private:
    bool isPossibleToRun(long long time, long long n,vector<int>& batteries)
    {
        long long sum = 0;
        for(int i : batteries)
        {
            sum+=min((long long)i, time);
            if(sum >= time*n)
                return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long low = *min_element(batteries.begin(),batteries.end());
        long long high = 0;
        for(int i : batteries)
        {
            high+=i;
        }
        high/=n;

        long long ans = 0;

        while(low<=high)
        {
            long long mid = (low+high)>>1;
            if(isPossibleToRun(mid, n, batteries))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};