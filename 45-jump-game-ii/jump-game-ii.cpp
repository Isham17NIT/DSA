class Solution {
public:
    int jump(vector<int>& nums) 
    {
        vector<int> jumps(nums.size(),INT_MAX);
        jumps[0]=0;
        int i=0;
        while(jumps[nums.size()-1]==INT_MAX)
        {
            for(int j=1;j<=nums[i] && i+j<nums.size();j++) //no. of jumps
            {
                jumps[i+j]=min(jumps[i+j],jumps[i]+1);
            }
            i++;
        }
        return jumps[nums.size()-1];
    }
};