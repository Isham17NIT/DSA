class Solution {
public:
    int totalMoney(int n) 
    {
        int numWeeks=n/7;
        int extraDays=n%7;
        int totalMoney = 0;
        int prev=numWeeks+1;
        while(numWeeks>0)
        {   
            totalMoney+=(3+numWeeks)*7;
            numWeeks--;
        } 
        while(extraDays>0)
        {
            totalMoney+=prev;
            prev+=1;
            extraDays--;
        }
        return totalMoney;
    }
};