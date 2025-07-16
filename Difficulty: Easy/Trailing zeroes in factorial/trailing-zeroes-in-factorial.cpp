// User function Template for C++
class Solution {
  public:
    int trailingZeroes(int n) 
    {
        int cnt=0;
        for(int i=5;n/i>0;i*=5){
            cnt += (n/i);
        }
        return cnt;
    }
};