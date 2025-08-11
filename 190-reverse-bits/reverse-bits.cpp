class Solution {
public:
    int reverseBits(int n){
        for(int i=0;i<16;i++)
        {
            //swap the bits at posn i and 16+i
            int mask1 = (1<<i);
            int mask2 = (1<<(31-i));
            int bit1 = (n&mask1)!=0 ? 1 : 0;
            int bit2 = (n&mask2)!=0 ? 1 : 0;
            if(bit1==bit2)
                continue;
            if(bit1 == 1)
            {
                n&=(~mask1);
                n|=mask2;
            }
            else //bit2==1
            {
                n&=(~mask2);
                n|=mask1;
            }
        }
        return n;
    }
};