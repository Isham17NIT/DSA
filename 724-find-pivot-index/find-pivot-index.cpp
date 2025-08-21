class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        int totalSum=0, leftSum=0;
        for(int i:nums)
        {
            totalSum+=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            leftSum+=nums[i];
            if(totalSum-leftSum==leftSum-nums[i])
                return i;
        }
        return -1;
    }
};