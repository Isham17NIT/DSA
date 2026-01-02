class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        int maxCups=0, totalCups=0;
        for(int i : amount)
        {
            maxCups = max(maxCups, i);
            totalCups+=i;
        }
        return max(maxCups, (totalCups+1)/2);
    }
};