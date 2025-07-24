class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<int> lp(n,0);
        vector<int> rp(n,0); 
        lp[0] = nums[0];
        rp[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
        {
            lp[i] = lp[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            rp[i] = rp[i+1]*nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
                ans[i] = rp[1];
            else if(i==n-1)
                ans[i] = lp[n-2];
            else{
                ans[i] = lp[i-1]*rp[i+1];
            }
        }
        return ans;
    }
};