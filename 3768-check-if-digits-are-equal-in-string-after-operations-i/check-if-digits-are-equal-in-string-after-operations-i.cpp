class Solution {
public:
    bool hasSameDigits(string s) 
    {
        // we'll do inplace modification
        int n=s.length();
        while(n>2)
        {
            for(int i=0;i<n-1;i++)
            {
                int newDigit=((s[i]-'0')+(s[i+1]-'0'))%10;
                s[i]=newDigit+'0';
            }
            n--;
        }
        return s[0]==s[1];
    }
};