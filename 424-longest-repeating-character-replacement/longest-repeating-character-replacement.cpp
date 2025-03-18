class Solution {
public:
    int findNewMaxFreq(unordered_map<char,int> freq)
    {
        int maxFreq=0;
        for(auto it : freq)
        {
            maxFreq=max(maxFreq, it.second);
        }
        return maxFreq;
    }
    int characterReplacement(string s, int k) 
    {
        int n=s.length();
        int l=0, maxLen=0, maxFreq=0, changes=0;

        unordered_map<char,int> freq;

        for(int r=0;r<n;r++)
        {
            freq[s[r]] += 1;
            if(maxFreq < freq[s[r]])
                maxFreq = freq[s[r]];
            
            changes = (r-l+1) - maxFreq;

            while(changes > k)
            {
                freq[s[l]] -= 1;
                if(freq[s[l]]==0)
                    freq.erase(s[l]);
                l++;
                
                maxFreq = findNewMaxFreq(freq);
                changes = (r-l+1) - maxFreq;
            }
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};