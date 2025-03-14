class Solution 
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s) 
    {
        if(s.size()==0) //no cookies to give to anyone
            return 0;
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(j<g.size() && s[i]>=g[j])
            {
                cnt++;
                j++;
            }
        }
        return cnt;
    }
};