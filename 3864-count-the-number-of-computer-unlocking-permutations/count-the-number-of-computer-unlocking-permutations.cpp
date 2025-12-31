class Solution {
public:
    int countPermutations(vector<int>& complexity) 
    {
        int n=complexity.size(), ans=1, mod=1e9+7;
        for(int i=1;i<n;i++)
        {
            if(complexity[i] <= complexity[0])
                return 0;
            ans = ((long long)ans*(long long)i)%mod;
        }
        return ans;
    }
};