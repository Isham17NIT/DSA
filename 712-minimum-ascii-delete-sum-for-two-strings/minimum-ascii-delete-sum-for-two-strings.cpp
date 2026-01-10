class Solution {
private:
    vector<vector<int>> findLCSMatrix(string &s1, string &s2)
    {
        int n=s1.size(), m=s2.size();
        vector<vector<int>> lcs(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    lcs[i][j] = (int)s1[i-1] + lcs[i-1][j-1];
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        return lcs;
    }
    int findASCIISum(string &s)
    {
        int ascii=0;
        for(char c : s){
            ascii += (int)c;
        }
        return ascii;
    }
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        // we need to find the longest common subsequence of the 2 strings
        vector<vector<int>> lcs = findLCSMatrix(s1, s2);
        return findASCIISum(s1) + findASCIISum(s2) - 2 * lcs[s1.size()][s2.size()];
    }
};