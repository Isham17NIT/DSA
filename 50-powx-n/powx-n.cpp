class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0)
            return 1;
        int sign = n<0 ? -1 : 1;
        double ans=1;
        if(n==INT_MIN)
        {
            ans*=x;
            n+=1;
        }
        n = abs(n);
        if(x < 0)
        {
            if(n&1) //odd power
                ans *= -1;
            x = abs(x);
        }
        
        if(n%2==0)
            ans *= myPow(x*x, n/2);
        else
            ans *= (x * myPow(x, n-1));
        if(sign==1)
            return ans;
        else
            return 1/ans;
    }
};