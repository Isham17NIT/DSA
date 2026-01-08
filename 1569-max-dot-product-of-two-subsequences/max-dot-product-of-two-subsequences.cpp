class Solution 
{
private:
    int calculateMaxDotProduct(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp)
    {
        if(idx1==nums1.size() || idx2==nums2.size())
            return -1e9;

        if(dp[idx1][idx2]!=-1e9)
            return dp[idx1][idx2];

        int val = nums1[idx1] * nums2[idx2];

        int take_i_j = val + calculateMaxDotProduct(idx1+1, idx2+1, nums1, nums2, dp);
        int take_j = calculateMaxDotProduct(idx1, idx2+1, nums1, nums2, dp);
        int take_i = calculateMaxDotProduct(idx1+1, idx2, nums1, nums2, dp);
    
        return dp[idx1][idx2]=max({val, take_i, take_j, take_i_j});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1e9));
        return calculateMaxDotProduct(0, 0, nums1, nums2, dp);
    }
};