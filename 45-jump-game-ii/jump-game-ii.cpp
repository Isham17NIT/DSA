class Solution 
{
public:
    int minJumps(vector<int>& nums,int idx,vector<int> &dp)
    {
        if(idx>=nums.size()-1)
            return 0; //no further jump needed
        if(dp[idx]!=-1)
            return dp[idx];
     
        int ans=INT_MAX;
        for(int i=1;i<=nums[idx];i++)
        {
            int curr=minJumps(nums,idx+i,dp);
            if(curr!=INT_MAX)
                ans=min(ans,1+curr);
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),-1);
        return minJumps(nums,0,dp);
    }
};