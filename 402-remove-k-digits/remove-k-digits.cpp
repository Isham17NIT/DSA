class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(k>=num.length())
            return "0";
        string ans="";
        for(int i=0;i<num.length();i++)
        {
            while(ans.length()>0 && ans.back()>num[i] && k>0)
            {
                ans.pop_back();
                k--;
            }
            if(ans.length()>0)
                ans+=num[i];
            else if(num[i]!='0') // as ans.lengthto avoid adding leading zeroes
                ans+=num[i];
        }
        // to handle the edge case    1 2 3 4 5
        while(k>0 && ans.size()>0)
        {
            ans.pop_back();
            k--;
        }
        return ans=="" ? "0" : ans;        
    }
};