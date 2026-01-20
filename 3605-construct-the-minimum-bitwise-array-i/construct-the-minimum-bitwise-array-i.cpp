class Solution 
{
private:
    int findMinCandidate(int x)
    {
        for(int i=1;i<x;i++)
        {
            if((i | (i+1)) == x)
                return i;
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i] = findMinCandidate(nums[i]);
        }
        return ans;
    }
};