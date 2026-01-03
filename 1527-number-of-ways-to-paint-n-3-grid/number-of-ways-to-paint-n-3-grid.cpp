class Solution {
private:
    int mod=1e9+7;
    unordered_map<string, vector<string>> getValidNextRows(vector<string> rows)
    {
        unordered_map<string, vector<string>> nextRows;
        for(string s : rows)
        {
            for(string x: rows)
            {
                if(s!=x && s[0]!=x[0] && s[1]!=x[1] && s[2]!=x[2])
                    nextRows[s].push_back(x);
            }
        }
        return nextRows;
    }    
    int findNumWays(int idx, string prevRow, int n, unordered_map<string, vector<string>> &nextRows, unordered_map<string,int> &dp)
    {
        if(idx==n) // found a way
            return 1;

        string key = to_string(idx)+"_"+prevRow;
        if(dp.find(key)!=dp.end())
            return dp[key];
        
        int ans=0;
        for(string s : nextRows[prevRow])
        {
            ans = (ans + findNumWays(idx+1, s, n, nextRows, dp)%mod)%mod;
        }
        return dp[key]=ans;        
    }

public:
    int numOfWays(int n) 
    {
        // two types of rows--> i) 2 color rows like YGY    ii) 3 color rows like RYG
        vector<string> rows= {"RYR","RGR","YRY","YGY","GRG","GYG","RYG","RGY","YRG","YGR","GRY","GYR"}; //O(1) space
        unordered_map<string, vector<string>> nextRows = getValidNextRows(rows); //O(1) space + tc
        unordered_map<string,int> dp;
        
        int ans=0;
        for(string s : rows) //for 0th row we can have any comb
        {
            ans = (ans + findNumWays(1, s, n, nextRows, dp)%mod)%mod;
        }
        return ans;
    }
};