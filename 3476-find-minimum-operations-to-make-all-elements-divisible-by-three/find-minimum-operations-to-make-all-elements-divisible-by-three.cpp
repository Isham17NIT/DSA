class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        // if num%3==1, subtact 1
        // if num%3==2, add 1
        int cnt=0;
        for(int i : nums)
        {
            if(i%3>=1)
                cnt+=1;
        }
        return cnt;
    }
};