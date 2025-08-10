class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left=0, right=0, sum=0, ans=nums.size();
        while(right < nums.size())
        {
            sum+=nums[right];
            if(sum>=target)
            {
                while(left<=right && sum>=target)
                {
                    ans=min(ans,right-left+1); 
                    sum-=nums[left++];
                }
            }   
            right++;
        }
        return left==0 && right==nums.size() && sum<target ? 0 : ans;
    }
};