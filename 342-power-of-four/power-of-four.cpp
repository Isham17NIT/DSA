class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if(n<=0 || (n&(n-1)) !=0) //no. is not a power of 2---> so can't be power of 4 as well
            return false;
        // 100 ---> posn of set bit is 2 (power of 4)
        // 1000 ---> posn of set bit is 3 (not a power of 4)
        // 10000 ---> posn of set bit is 4 (power of 4)
        int cnt=0;
        while(n!=1)
        {
            n=n>>1;
            cnt++;
        }
        if(cnt&1)
            return false;
        return true;
    }
};