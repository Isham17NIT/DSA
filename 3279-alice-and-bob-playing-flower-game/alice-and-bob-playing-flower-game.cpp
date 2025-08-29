class Solution {
public:
    long long flowerGame(int n, int m) 
    {
        if(n==1 && m==1)
            return 0;
        return floor((long long)m*(long long)n/2);
    }
};