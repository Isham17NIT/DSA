class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(string s : strs)
        {
            string freq;
            vector<int> f(26,0);
            for(char c : s)
            {
                f[c-'a']+=1;
            }
            for(int i=0;i<26;i++)
            {
                freq=freq+to_string(f[i])+",";
            }
            if(m.find(freq)!=m.end())
                m[freq].push_back(s);
            else{
                m[freq] = vector<string>();
                m[freq].push_back(s);
            }
        }
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};