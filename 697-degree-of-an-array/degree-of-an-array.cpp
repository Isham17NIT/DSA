class Solution 
{
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int,vector<int>> m; // element : (start_idx,last_idx,freq)
        int maxDegree = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
                m[nums[i]] = {i,i,1};
            else
            {
                m[nums[i]][1] = i;
                m[nums[i]][2] += 1;
                maxDegree = max(m[nums[i]][2],maxDegree);
            }
        }
        int ans = nums.size();
        for(auto &it : m)
        {
            if(it.second[2]==maxDegree)
            {
                ans = min(ans, it.second[1]-it.second[0]+1);
            }
        }
        return ans;
    }
};