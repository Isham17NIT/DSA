class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;
        int start=0, end=0;   
        while(end<nums.size())
        {
            if(end!=nums.size()-1 && nums[end] + 1 == nums[end+1])
                end++;
            else{
                if(start!=end)
                    ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                else
                    ans.push_back(to_string(nums[start]));
                end++;
                start=end;
            }
        }
        return ans;
    }
};