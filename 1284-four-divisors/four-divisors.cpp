class Solution {
private:
    int getDivisorsSum(int num)
    {
        int sum=0, divCount=0;
        for(int i=1;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                int other=num/i;
                sum+=i;

                if(i==other)
                    divCount+=1;
                else{
                    divCount+=2;
                    sum+=other;
                }
                if(divCount>4)
                    break;
            }
        }
        return divCount==4 ? sum : 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        int ans=0;
        for(int i : nums)
        {
            ans+=getDivisorsSum(i);
        }
        return ans;
    }
};