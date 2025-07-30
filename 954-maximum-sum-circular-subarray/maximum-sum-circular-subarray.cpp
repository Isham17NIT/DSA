class Solution {
private:
    int findMinSubarraySum(vector<int> &nums)
    {
        int minSum=nums[0], currSum=0;
        for(int i : nums)
        {
            currSum+=i;
            minSum=min(minSum, currSum);
            if(currSum>0)
                currSum=0;
        }
        return minSum;
    }
    int findMaxSubarraySum(vector<int> &nums)
    {
        int maxSum=nums[0], currSum=0;
        for(int i : nums)
        {
            currSum+=i;
            maxSum=max(maxSum, currSum);
            if(currSum<0)
                currSum=0;
        }
        return maxSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int total=0;
        for(int i:nums)
        {
            total+=i;
        }
        int sum1=findMaxSubarraySum(nums);
        int sum2=findMinSubarraySum(nums);
        if(sum2==total)
            return sum1;
        return max(sum1, total - sum2);
    }
};