class Solution {
public:
    int findContentChildren(vector<int> g, vector<int> s) 
    {
        if(s.size()==0) //no cookies to give to anyone
            return 0;
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            if(!g.empty() && s[i]>=g[0])
            {
                cnt++;
                g.erase(g.begin());
            }
        }
        return cnt;
    }
};