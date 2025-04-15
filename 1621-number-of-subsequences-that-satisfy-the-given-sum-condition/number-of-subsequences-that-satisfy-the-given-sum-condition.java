class Solution {
    public int numSubseq(int[] nums, int target) 
    {
        Arrays.sort(nums);
        int n=nums.length;
        int l=0,r=n-1,ans=0;
        int powers[]=new int[n];
        int mod = (int)1e9 + 7;
        powers[0]=1;
        for(int i=1;i<n;i++)
        {
            powers[i] = (powers[i-1]*2)%mod;
        }
        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                ans = (ans + powers[r-l])%mod;
                l++;
            }
            else
                r--;
        }
        return ans;
    }
}