class Solution 
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size(), n=nums2.size();
        vector<int> dp(n, -1e9);
        dp[0] = nums1[0] * nums2[0];

        for(int j=1;j<n;j++)
        {
            dp[j] = max(dp[j-1], nums1[0]*nums2[j]);
        }
        for(int i=1;i<m;i++)
        {
            vector<int> curr(n, -1e9);
            curr[0] = max(dp[0], nums1[i]*nums2[0]);
            for(int j=1;j<n;j++)
            {
                int val = nums1[i] * nums2[j];
                int take_i_j = val + dp[j-1];
                int take_j = curr[j-1];
                int take_i = dp[j];
                curr[j] = max({val, take_i_j, take_j, take_i});
            }
            dp=curr;
        }
        return dp[n-1];
    }
};