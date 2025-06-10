class Solution 
{
public:
    int maxDifference(string s) 
    {
        vector<int> freq(26,0);
        int maxOddFreq=0, minEvenFreq=INT_MAX;
        for(char c : s)
        {
            freq[c-'a']+=1;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0) //check only for those chars which exist in the string
            {
                if(freq[i]&1)
                    maxOddFreq = max(maxOddFreq, freq[i]);
                else
                    minEvenFreq = min(minEvenFreq, freq[i]);
            }
        }
        return maxOddFreq - minEvenFreq;
    }
};