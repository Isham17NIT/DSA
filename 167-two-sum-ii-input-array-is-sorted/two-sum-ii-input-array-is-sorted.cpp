class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int low=0, high=nums.size()-1;
        while(low<high)
        {
            int currSum = nums[low]+nums[high];
            if(currSum==target)
                return {low+1, high+1};
            else if(currSum < target)
                low++;
            else
                high--;
        }
        return vector<int>();
    }
};