class Solution 
{
private:
    int calculateSum(vector<int> &arr)
    {
        int sum=0;
        for(int i:arr)
        {
            sum+=i;
        }
        return sum;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        if(calculateSum(gas) < calculateSum(cost))
            return -1; //never possible
        int start=0;
        int gasLeft=gas[0];
        for(int i=0;i<gas.size()-1;i++)
        {
            gasLeft-=cost[i];
            if(gasLeft < 0){
                start=i+1;
                gasLeft=gas[i+1];
                continue;
            }
            else{
                gasLeft+=gas[i+1];
            }
        }
        return start;
    }
};