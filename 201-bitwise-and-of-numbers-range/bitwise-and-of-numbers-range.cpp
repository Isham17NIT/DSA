class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        if(left==0 || left==right)
            return left;
        int cnt=0;
        while(right!=left)
        {
            right>>=1;
            left>>=1;
            cnt++;
        }
        return right << cnt;        
    }
};




// 10->001010
// 11->001011
// 12->001100
// 13->001101
//     001000