class Solution {
  public:
    vector<int> search(string &pat, string &txt) 
    {
        vector<int> ans;
        int n=txt.size(), m=pat.size();
        int p=37; // prime no. for rolling hash fn
        int mod=1e9+7;
        
        //compute powers, hash value of the given pattern and first substring of txt
        
        long long patHash=pat[0]-'a'+1; // hash value of pattern
        vector<long long> txtHash(n,0);
        txtHash[0]=txt[0]-'a'+1;
        long long power=1;
        for(int i=1;i<m;i++)
        {
            power=(power*p)%mod;
            patHash=(patHash*p + (pat[i]-'a'+1))%mod;
            txtHash[i]=(txtHash[i-1]*p + (txt[i]-'a'+1))%mod;
        }
        if(txtHash[m-1]==patHash && txt.substr(0,m)==pat)
            ans.push_back(0); // first substring of txt matches with pat
        
        // compute hash values of all other substrings of txt
        for(int i=m;i<n;i++)
        {
            int newChar = txt[i]-'a'+1;
            int firstChar = txt[i-m]-'a'+1;
            long long rmv = (1LL * firstChar * power) % mod;
            long long prev = (txtHash[i-1] - rmv + mod) % mod;
            txtHash[i] = ((p * prev)%mod + newChar) % mod;
            if(txtHash[i]==patHash && txt.substr(i-m+1,m)==pat)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};







