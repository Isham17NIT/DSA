class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char> mappings;
        vector<bool> mapped(256,false);
        for(int i=0;i<s.length();i++)
        {
            if(mappings.find(s[i])!=mappings.end())
            {
                if(t[i]!=mappings[s[i]])
                    return false;
            }
            else
            {
                if(mapped[(int)t[i]])
                    return false;
                else
                {
                    mappings[s[i]] = t[i];
                    mapped[(int)t[i]] = true;
                }  
            }               
        }
        return true;
    }
};