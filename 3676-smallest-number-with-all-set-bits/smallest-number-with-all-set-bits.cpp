class Solution {
public:
    int smallestNumber(int n) 
    {
        int orig=n;
        int i=floor(log2(n)); // i+1 is the number of bits in binary rep
        vector<int> powers(i+1); // stores powers of 2
        vector<int> unsetBits; // bit posn where bit is unset

        powers[0]=1;
        for(int k=1;k<=i;k++)
        {
            powers[k]=powers[k-1]*2;
        }
        while(i>=0)
        {
            if(n>=powers[i])
                n%=powers[i];
            else
                unsetBits.push_back(i);
            i--;
        }
        for(int k: unsetBits)
        {
            orig+=powers[k];
        }
        return orig;        
    }
};

