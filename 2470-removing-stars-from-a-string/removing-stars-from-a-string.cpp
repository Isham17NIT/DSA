class Solution {
public:
    string removeStars(string str) 
    {
        string ans="";
        for(char c : str)
        {
            if(c=='*'){
                if(!ans.empty())
                    ans.pop_back();
            }
            else
                ans+=c;
        }
        return ans;
    }
};