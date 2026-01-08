class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) 
    {
        vector<int> diff;
        int ones=0, zeros=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i]){
                diff.push_back(i);
                if(s[i]=='1')
                    ones++;
                else
                    zeros++;
            }
        }
        if(diff.size()==0)
            return 0;

        long long res1, res2, res3;
        long long swaps = min(ones, zeros);
        long long remaining = abs(ones-zeros);
        res1 = (long long)diff.size() * (long long)flipCost;
        res2 = (long long)swapCost * swaps + (long long)flipCost * remaining;
        res3 = (long long)swapCost * swaps + (long long)(crossCost + swapCost) * (remaining/2);
        if(remaining % 2 == 1)
            res3+=flipCost;

        return min({res1, res2, res3});
    }
};