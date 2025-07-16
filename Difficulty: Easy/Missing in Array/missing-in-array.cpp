class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size()+1;
        //xor1 -> xor of numbers from 1 to n
        //xor2 -> xor of given numbers
        int xor1=0, xor2=0; 
        if(n%4==0)
            xor1 = n;
        else if(n%4==1)
            xor1 = 1;
        else if(n%4==2)
            xor1=n+1;
        else
            xor1=0;
        for(int i : arr)
        {
            xor2 ^= i;
        }
        return (xor1 ^ xor2);
        
    }
};