class Solution 
{
private:
    unordered_map<string, bool> memo;

    bool buildPyramid(int idx, string currLevel, string nextLevel, unordered_map<string, vector<char>> &m)
    {
        if(nextLevel.size() == 1) // pyramid is formed and we are at the top
            return true;

        string key = nextLevel + "_" + to_string(idx) + "_" + currLevel;

        if(memo.find(key)!=memo.end())
            return memo[key];

        if(idx == nextLevel.size()-1)
        {
            return memo[key] = buildPyramid(0, "", currLevel, m);
        }

        string x = nextLevel.substr(idx,2);

        if(m.find(x)==m.end())
            return memo[key] = false;

        for(char &ch : m[x])
        {
            if(buildPyramid(idx+1, currLevel + ch, nextLevel, m))
                return memo[key] = true;
        }
        return memo[key] = false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) 
    {
        unordered_map<string, vector<char>> m;
        for(string s : allowed)
        {
            m[s.substr(0,2)].push_back(s[2]);
        }
        return buildPyramid(0, "", bottom, m);
    }
};