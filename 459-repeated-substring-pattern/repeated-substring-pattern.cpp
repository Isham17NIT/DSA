class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n=s.length();
        int l=n/2; //maxm length of substr ---> corr. to minm 2 repetitions
        for(int i=1;i<=l;i++)
        {
            if(n%i==0)
            {
                string str=s.substr(0,i);
                string tmp="";
                for(int j=0;j<n/i;j++)
                {
                    tmp+=str;
                }
                if(tmp==s)
                    return true;
            }
        }
        return false;
    }
};