class Solution 
{
public:
    string largestGoodInteger(string num) 
    {
        string ans="";
        for(int i=1;i+1<num.size();i+=1)
        {
            if(num[i-1]==num[i] && num[i]==num[i+1])
            {
                if(ans=="" || ans[0]-'0' < num[i]-'0')
                    ans=num.substr(i-1,3);
            }
        }
        return ans;
    }
};