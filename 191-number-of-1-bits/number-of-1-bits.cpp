class Solution {
public:
    int hammingWeight(int n) 
    {
        int cnt=1;
        while(n&(n-1)){
            cnt++;
            n&=(n-1);
        }
        return cnt;
    }
};