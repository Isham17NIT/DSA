class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        int maxPairSum=0;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n/2;i++)
        {
            maxPairSum = max(maxPairSum, nums[i] + nums[n-1-i]);
        }
        return maxPairSum;
    }
};