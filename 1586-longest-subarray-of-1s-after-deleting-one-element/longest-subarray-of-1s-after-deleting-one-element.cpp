class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int start=0, idx=-1; // idx--->idx of previous non-1 element
        int ans=0, i=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=1){
                if(idx==-1){
                    idx=i; 
                }                                 
                else{
                    ans=max(ans,i-1-start);
                    start=idx+1;
                    idx=i;
                }
            }
        }
        if(idx!=-1)
            return max(ans, (int)(nums.size())-start-1);
        // all ones
        return (int)nums.size()-1;
    }
};