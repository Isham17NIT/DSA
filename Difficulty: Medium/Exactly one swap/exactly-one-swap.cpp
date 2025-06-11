class Solution {
  public:
    int countStrings(string &s) 
    {
        vector<int> freq(26,0);
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            cnt += (i-freq[s[i]-'a']);
            freq[s[i]-'a']+=1;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]>1)
            {
                cnt+=1;
                break;
            }
        }
        return cnt;
    }
};
