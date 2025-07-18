class Solution 
{
private:
    bool isAlphaNum(char c)
    {
        return (c>='a' && c<='z') || (c>='0' && c<='9');
    }
public:
    bool isPalindrome(string s) 
    {
        int i=0, j=s.length()-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(i<j)
        {
            if(isAlphaNum(s[i]) && isAlphaNum(s[j]))
            {
                if(s[i]!=s[j])
                    return false;
                i++; j--;
            }
            else if(isAlphaNum(s[i]))
                j--;
            else
                i++;
        }
        return true;
    }
};