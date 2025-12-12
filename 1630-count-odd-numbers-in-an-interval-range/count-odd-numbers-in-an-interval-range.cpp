class Solution {
public:
    int countOdds(int low, int high) 
    {
        if(high==low)
            return low%2;
        else if(low==0)
            return (high+1)/2;
        else if(low%2 || high%2)
            return (high-low)/2 + 1;
        return (high-low)/2;
    }
};