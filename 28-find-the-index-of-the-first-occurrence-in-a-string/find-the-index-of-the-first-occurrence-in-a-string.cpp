class Solution 
{
private:
    vector<int> computeLPS(string s)
    {
        vector<int> lps(s.size());
        lps[0]=0;
        int len=0, i=1;
        while(i<s.size())
        {
            if(s[len]==s[i])
            {
                lps[i]=len+1;
                len++;
                i++;
            }
            else
            {
                if(len>0)
                    len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            } 
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) 
    {
        vector<int> lps = computeLPS(needle);
        int j=0, i=0;
        while(i<haystack.size())
        {
            if(haystack[i]==needle[j]){
                i++; j++;
                if(j==needle.size())
                    return i-needle.size();
            }
            else{
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
};