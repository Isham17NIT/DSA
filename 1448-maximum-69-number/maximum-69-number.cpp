class Solution {
public:
    int maximum69Number (int num) 
    {
        int cnt=0; //cnt of the digits
        int pos=-1; //posn of the first 6 from starting
        int temp=num;
        while(temp)
        {
            int digit=temp%10;
            if(digit==6)
                pos=cnt;
            temp/=10;
            cnt++;
        }
        if(pos==-1) //no 6 present---> all 9's
            return num;
        return num + 3*(int)pow(10, pos);
    }
};