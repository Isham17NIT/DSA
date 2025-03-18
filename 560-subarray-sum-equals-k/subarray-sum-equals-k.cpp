class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int prefixSum=0;
        int cnt=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum += nums[i];
            if(m.find(prefixSum-k)!=m.end())
                cnt += m[prefixSum-k];
            m[prefixSum]+=1;
        }
        return cnt;
    }
};