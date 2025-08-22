class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int start=0, idx=-1; // idx--->idx of previous non-1 element
        int ans=0, n=nums.size();
        for(int i=0;i<n;i++)
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
            return max(ans, n-start-1);
        // all ones
        return n-1;
    }
};