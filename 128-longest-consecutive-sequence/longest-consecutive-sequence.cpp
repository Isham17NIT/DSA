class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        int longest=1, curr=1;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==prev)
                continue;
            else if(nums[i]==1+prev)
            {
                curr++;
                longest=max(longest,curr);
                prev=nums[i];
            }
            else{
                curr=1;
                prev=nums[i];
            }
        }
        return longest;
    }
};