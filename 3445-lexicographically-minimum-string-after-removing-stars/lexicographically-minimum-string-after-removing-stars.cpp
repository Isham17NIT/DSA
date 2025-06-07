class Solution 
{
public:
    string clearStars(string s) 
    {
        vector<stack<int>> arr(26,stack<int>());
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            if(c=='*')
            {
                for(int j=0;j<26;j++)
                {
                    if(!arr[j].empty())
                    {
                        s[arr[j].top()]='*';
                        arr[j].pop();
                        break;
                    }
                }
            }
            else
            {
                arr[c-'a'].push(i);
            }
        }
        string ans="";
        for(char c : s)
        {
            if(c!='*')
            {
                ans += c;
            }
        }
        return ans;
    }
};