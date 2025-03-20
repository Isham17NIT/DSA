class Solution {
public:
    int countSubarraysLessThanEqualToGoal(vector<int>& nums, int goal)
    {
        int cnt=0, l=0, r=0, sum=0;
        while(r<nums.size())
        {
            sum += nums[r];
            while(l<=r && sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return countSubarraysLessThanEqualToGoal(nums,goal)-countSubarraysLessThanEqualToGoal(nums,goal-1);
    }
};