class Solution 
{
public:
    int superEggDrop(int k, int n) 
    {
        vector<int> prev(k+1,0);
        int cnt=0;
        while(prev[k] < n)
        {
            cnt++;
            vector<int> curr(k+1,0);
            for(int i=1;i<=k;i++)
            {
                curr[i] = 1 + prev[i-1] + prev[i];
            }
            prev=curr;
        }
        return cnt;
    }
};