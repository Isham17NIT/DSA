class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int k=0, idx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                k++;
                swap(nums[++idx],nums[i]);
            }
        }
        return k;
    }
};