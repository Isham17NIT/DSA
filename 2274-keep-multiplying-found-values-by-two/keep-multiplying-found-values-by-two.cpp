class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        unordered_set<int> s;
        for(int i : nums)
        {
            s.insert(i);
        }
        while(s.find(original)!=s.end())
        {
            original*=2;
        }
        return original;
    }
};