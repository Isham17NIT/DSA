class Solution {
public:
    string longestPrefix(string s) 
    {
        vector<int> lps(s.length(),0);
        lps[0]=0;
        int len=0,i=1;
        while(i<s.length())
        {
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)
                    len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }    
            }
        }
        return s.substr(0,len);
    }
};