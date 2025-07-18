class Solution 
{
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int,int> freq;
        int maxmFreq=0, ans=0;
        for(int i : nums)
        {
            freq[i] += 1;
            if(maxmFreq < freq[i]){
                maxmFreq = freq[i];
                ans = freq[i];
            }
            else if(maxmFreq == freq[i]){
                ans += freq[i];
            }
        }
        return ans;
    }
};