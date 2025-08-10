class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        unordered_set<int> s;
        int longest=1, curr=1;
        for(int i : nums)
        {
            s.insert(i);
        }
        for(int i : s)
        {
            if(s.find(i-1)!=s.end()) //means i is not the starting pt of the seq
                continue;
            else // i is the starting pt of the seq
            {
                curr=1;
                int j=1;
                while(s.find(i+j)!=s.end())
                {
                    curr++;
                    j++;
                }
                longest=max(longest, curr);
            }
        }
        return longest;
    }
};