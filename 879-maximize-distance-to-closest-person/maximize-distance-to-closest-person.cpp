class Solution 
{
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int ans=0, n=seats.size();
        int prevFilled=-1;
        for(int i=0;i<n;i++)
        {
            if(seats[i]==0)
                continue;
            if(prevFilled==-1) //first filled seat
            {
                prevFilled=i;
                ans = max(ans, i);
            }
            else
            {
                int k = i-prevFilled-1;
                ans = max(ans, (k+1)/2);
                prevFilled=i;
            }
        }
        if(prevFilled < n)
            ans=max(ans, n-prevFilled-1);
        return ans;
    }
};