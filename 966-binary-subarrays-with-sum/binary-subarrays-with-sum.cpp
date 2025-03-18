class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0, cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(m.find(sum-k)!=m.end())
                cnt+=m[sum-k];
            m[sum]+=1;
        }
        return cnt;
    }
};