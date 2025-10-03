class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n=s.length();
        return (s+s).substr(1,n*2-2).find(s)!=-1;
    }
};