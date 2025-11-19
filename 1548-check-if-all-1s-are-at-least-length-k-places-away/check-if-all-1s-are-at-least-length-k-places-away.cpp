class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int prevIdx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                if(prevIdx==-1 || i-prevIdx>=k+1)
                    prevIdx=i;
                else
                    return false;
            }
        }
        return true;
    }
};