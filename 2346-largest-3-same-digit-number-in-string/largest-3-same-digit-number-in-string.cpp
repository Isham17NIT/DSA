class Solution 
{
public:
    string largestGoodInteger(string num) 
    {
        int prevLen=1;
        string ans="";
        for(int i=1;i<num.size();i++)
        {
            if(prevLen>=1 && num[i-1]==num[i])
            {
                prevLen++;
                if(prevLen==3)
                {
                    if(ans=="")
                        ans=num.substr(i-2,3);
                    else if(ans[0]-'0' < num[i]-'0')
                        ans=num.substr(i-2,3);
                }
            }
            else
                prevLen=1;
        }
        return ans;
    }
};