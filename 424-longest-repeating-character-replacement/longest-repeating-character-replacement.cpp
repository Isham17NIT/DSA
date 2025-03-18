class Solution {
public:
    pair<int,char> findNewMaxFreq(int freq[26])
    {
        int maxFreq=0;
        char maxFreqChar;
        for(int i=0;i<26;i++)
        {
            if(maxFreq < freq[i])
            {
                maxFreq = freq[i];
                maxFreqChar = i+'A';
            }
        }
        return {maxFreq,maxFreqChar};
    }
    int characterReplacement(string s, int k) 
    {
        int n=s.length();
        int l=0, maxLen=0, maxFreq=0, changes=0;
        char maxFreqChar;
        int freq[26];
        for(int i=0;i<26;i++)
        {
            freq[i]=0;
        }

        for(int r=0;r<n;r++)
        {
            freq[s[r]-'A'] += 1;
            if(maxFreq < freq[s[r]-'A'])
            {
                maxFreq = freq[s[r]-'A'];
                maxFreqChar = s[r];
            }
            
            changes = (r-l+1) - maxFreq;

            if(changes <= k)
            {
                maxLen = max(maxLen,r-l+1);
            }
            else
            {
                while(changes > k)
                {
                    freq[s[l]-'A'] -= 1;
                    l++;
                    if(s[l] == maxFreqChar)
                    {
                        pair<int,char> p = findNewMaxFreq(freq);
                        maxFreq = p.first;
                        maxFreqChar = p.second;
                    }
                    changes = (r-l+1) - maxFreq;
                }
            }
        }
        return maxLen;
    }
};