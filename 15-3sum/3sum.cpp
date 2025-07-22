class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int j = i+1, k=nums.size()-1;
            while(j<k)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                    j++;
                if(k!=nums.size()-1 && nums[k]==nums[k+1])
                    k--;
                if(j>=k)
                    break;
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }                    
                else if(sum<0)
                    j++;
                else
                    k--;
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};