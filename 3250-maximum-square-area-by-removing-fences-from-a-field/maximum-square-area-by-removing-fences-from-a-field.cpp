class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hBars, vector<int>& vBars) 
    {
        int mod=1e9+7, len=-1;
        hBars.push_back(1);
        hBars.push_back(m);
        vBars.push_back(1);
        vBars.push_back(n);

        sort(vBars.begin(), vBars.end()); //O(1) due to less size
        sort(hBars.begin(), hBars.end()); // O(1) due to less size

        set<int> possibleLengths;
        for(int i=0;i<hBars.size();i++)
        {
            for(int j=i+1;j<hBars.size();j++)
            {
                possibleLengths.insert(hBars[j]-hBars[i]);
            }
        }
        for(int i=0;i<vBars.size();i++)
        {
            for(int j=i+1;j<vBars.size();j++)
            {
                if(possibleLengths.find(vBars[j]-vBars[i])!=possibleLengths.end())
                    len = max(len, vBars[j]-vBars[i]);
            }
        }
        if(len==-1)
            return -1;
        return ((long long)len * (long long)len) % mod;       
    }
};