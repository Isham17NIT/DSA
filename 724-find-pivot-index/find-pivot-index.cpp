class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        vector<int> prefixSums(nums.size());
        int totalSum;
        prefixSums[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSums[i]=nums[i]+prefixSums[i-1];
        }
        totalSum=prefixSums[nums.size()-1];
        if(totalSum-nums[0]==0)
            return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(totalSum-prefixSums[i]==prefixSums[i-1])
                return i;
        }
        return -1;
    }
};