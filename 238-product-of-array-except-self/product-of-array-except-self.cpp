class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n,0);
        int prod=1;
        // left Products------>ans[i] will be product of all elements from 0 to i-1
        for(int i=1;i<n;i++)
        {
            ans[i] = prod*nums[i-1];
            prod = ans[i];
        }
        prod = 1;
        for(int i=n-2;i>=0;i--)
        {
            if(i==0)
                ans[i] = nums[i+1]*prod;
            else
                ans[i] = ans[i]*nums[i+1]*prod;
            prod = nums[i+1]*prod;
        }
        return ans;
    }
};