class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int fives=0; //count of $5 coins
        int tens=0; //count of $10 coins
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
                fives++;
            else if(bills[i]==10)
            {
                if(fives==0)
                    return false;
                else
                    fives--;
                tens++;
            }
            else //bills[i]=20 -->I'll try to give minm $5 coins-->so that they can be distributed to others
            {
                if(tens==0)
                {
                    if(fives<3)
                        return false;
                    else
                        fives-=3;
                }
                else
                {
                    tens-=1;
                    if(fives==0)
                        return false;
                    else
                        fives-=1;
                }
            }
        }
        return true;
    }
};
