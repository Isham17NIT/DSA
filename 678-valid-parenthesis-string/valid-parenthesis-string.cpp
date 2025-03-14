class Solution {
public:
    bool checkValidString(string s) 
    {
        int min=0,max=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                min+=1;
                max+=1;
            }
            else if(s[i]==')')
            {
                if(min==0 && max==0)
                    return false;
                min = min>0 ? min-1 : min;
                max = max - 1;
            }
            else
            {
                min = min>0 ? min-1 : min;
                max = max + 1;
            }
        }
        return min==0;
    }
};