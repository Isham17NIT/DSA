class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(k==1)
            return vector<int>(nums.begin(),nums.end());

        vector<int> ans;
        map<int,int> freq;
        for(int i=0;i<k;i++) //first window
        {
            freq[nums[i]]+=1;
        }
        ans.push_back(freq.rbegin()->first);
        for(int i=k;i<nums.size();i++)
        {
            int x = nums[i-k];
            freq[x] -= 1;
            if(freq[x] == 0)
                freq.erase(x);
            freq[nums[i]]+=1;
            ans.push_back(freq.rbegin()->first);
        }
        return ans;
    }
};