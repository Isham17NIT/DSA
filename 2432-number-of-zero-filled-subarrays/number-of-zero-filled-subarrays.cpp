class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans=0;
        int start=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0){
                if(start!=-1) //means a subarray with 0 exists
                {
                    int n=i-start;
                    ans=ans+((long long)n*(long long)(n+1))/2;
                }
                start=-1;
            }                
            else if(start==-1) //nums[i]=0 and start=-1
                start=i;
        }
        if(start!=-1){
            int n=nums.size()-start;
            ans=ans+((long long)n*(long long)(n+1))/2;
        }
        return ans;
    }
};