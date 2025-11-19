class Solution {
private:
    long long findSubstrings(long long n)
    {
        return n*(n+1)/2;
    }
public:
    int numSub(string s) 
    {
        int ans=0, mod=1e9+7;
        int prevIdx=-1; //idx of starting 1 in the current substring 
        for(int i=0;i<s.length();i++)
        {
            if(prevIdx==-1)
            {
                if(s[i]=='1')
                    prevIdx=i;
                else //s[i]=='0'
                    continue;
            } 
            else if(s[i]=='0')
            {
                int n=i-prevIdx;  // no. of consecutive ones
                ans=(ans+findSubstrings(n))%mod;
                prevIdx=-1;
            }
            else //s[i]=='1'
                continue;
        }
        if(s[s.length()-1]=='1')
        {
            if(prevIdx==-1)
                ans=(ans+1)%mod;
            else
            {
                int n=s.length()-prevIdx;  // no. of consecutive ones
                ans=(ans+findSubstrings(n))%mod;
            }
        }
        return ans;
    }
};