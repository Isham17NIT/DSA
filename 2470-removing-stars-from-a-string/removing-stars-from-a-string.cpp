class Solution {
public:
    string removeStars(string s) 
    {
        int k=-1;
        for(char c : s)
        {
            if(c=='*'){
                if(k>-1)
                    k--;
            }
            else{
                s[++k]=c;
            }
        }
        return s.substr(0,k+1);
    }
};