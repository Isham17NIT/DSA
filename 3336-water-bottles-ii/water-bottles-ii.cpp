class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) 
    {
        int cnt=numBottles;
        while(numBottles>=numExchange)
        {
            numBottles=numBottles-numExchange+1;
            cnt+=1;
            numExchange+=1;
        }
        return cnt;
    }
};