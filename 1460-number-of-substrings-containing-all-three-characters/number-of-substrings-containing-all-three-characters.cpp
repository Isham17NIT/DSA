class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int cnt=0, l=0, r=0;
        unordered_map<int,int> m;
        m['a']=0; m['b']=0; m['c']=0;
        while(r < s.length())
        {
            m[s[r]] += 1;
            while(m['a']>=1 && m['b']>=1 && m['c']>=1)
            {
                cnt += (s.length()-r);
                m[s[l]]-=1;
                l++;
            }
            r++;
        }
        return cnt;
    }
};