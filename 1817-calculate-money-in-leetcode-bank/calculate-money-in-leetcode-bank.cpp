class Solution {
public:
    int totalMoney(int n) 
    {
        int numWeeks=n/7;
        int extraDays=n%7;
        int totalMoney = 7*(3*numWeeks + numWeeks*(numWeeks+1)/2);
        totalMoney+=(numWeeks*extraDays + extraDays*(extraDays+1)/2);
        return totalMoney;
    }
};