class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int m=word1.length(), n=word2.length();
        string ans;
        ans.reserve(m+n);
        int j=0;
        while(j<min(m,n))
        {
            ans += word1[j];
            ans += word2[j];
            j++;
        }
        ans += j<m ? word1.substr(j) : word2.substr(j);
        return ans; 
    }
};