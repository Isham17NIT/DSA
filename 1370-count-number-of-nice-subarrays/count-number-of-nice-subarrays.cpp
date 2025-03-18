class Solution 
{
public:
    int countSubarrays(vector<int> &nums,int k) //count of subarrays with cnt of odd <= k
    {
        int l=0, r=0, odd=0, cnt=0;
        while(r<nums.size())
        {
            if(nums[r] & 1)
                odd++;
            while(odd > k)
            {
                if(nums[l] & 1)
                    odd--;
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return countSubarrays(nums, k) - countSubarrays(nums, k-1);       
    }
};