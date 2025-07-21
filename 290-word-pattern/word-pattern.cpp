class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> map1(26,"");
        unordered_map<string,char> map2;
        stringstream ss(s);
        string token="";
        int i=0;
        while(getline(ss,token,' ')){
            if(i==pattern.size())
                return false;
            if(map2.find(token)!=map2.end()){
                if(map2[token]!=pattern[i])
                    return false;
            }
            else
            {
                if(map1[pattern[i]-'a']!="")
                    return false;
                map2[token] = pattern[i];
                map1[pattern[i]-'a'] = token;
            }
            i++;
        }
        if(i<pattern.length())
            return false;
        return true;
    }
};