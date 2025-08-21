class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        int totalSum=0, prevSum=0, currSum=0;
        for(int i:nums)
        {
            totalSum+=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            prevSum=currSum;
            currSum+=nums[i];
            if(totalSum-currSum==prevSum)
                return i;
        }
        return -1;
    }
};