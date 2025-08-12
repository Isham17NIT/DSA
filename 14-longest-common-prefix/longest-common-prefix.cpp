class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(),strs.end());
        //find common prefix of strs[0] and strs[1]
        int i=0, j=0, m=strs[0].size(), n=strs[strs.size()-1].length();
        string ans="";
        while(i<m && j<n)
        {
            if(strs[0][i]==strs[strs.size()-1][j])
            {
                ans+=strs[0][i];
            }
            else
                break;
            i++; j++;
        }
        return ans;
    }
};