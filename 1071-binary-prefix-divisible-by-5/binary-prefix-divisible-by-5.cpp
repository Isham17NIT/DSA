class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        vector<bool> ans;
        int num=0;
        for(int i : nums)
        {
            num=((long long)num*2+(long long)i)%5;
            ans.push_back(num==0);
        }
        return ans;
    }
};