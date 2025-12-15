class Solution {
public:
    int countPartitions(vector<int>& nums) 
    {
        int cnt=0;
        vector<int> prefixSum(nums.size(),0);
        // prefixSum[i]=sum of all elements from idx 0 to idx i(inclusive)
        prefixSum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        int totalSum=prefixSum.back();
        for(int i=0;i<nums.size()-1;i++)
        {
            if(abs(prefixSum[i] -(totalSum-prefixSum[i]))%2==0)
                cnt++;
        }
        return cnt;
    }
};