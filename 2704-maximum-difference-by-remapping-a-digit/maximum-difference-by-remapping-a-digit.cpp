class Solution{
private:
    int findMaxm(vector<int> &nums, int maxMapping)
    {
        int n=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==maxMapping)
                n = n*10 + 9;
            else
                n = n*10 + nums[i];
        }
        return n;
    }
    int findMinm(vector<int> &nums, int minMapping)
    {
        int n=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==minMapping)
                n = n*10 + 0;
            else
                n = n*10 + nums[i];
        }
        return n;
    }
public:
    int minMaxDifference(int num) 
    {
        vector<int> nums;
        int temp=num, maxMapping=-1, minMapping=-1;
        while(temp > 0)
        {
            int digit = temp%10;
            temp/=10;
            nums.push_back(digit);
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<9 && maxMapping==-1){
                maxMapping = nums[i];
            }
            if(nums[i]>0 && minMapping==-1){
                minMapping = nums[i];
            }
        }
        int maxm = maxMapping==-1 ? num : findMaxm(nums, maxMapping);
        int minm = minMapping==-1 ? num : findMinm(nums, minMapping);
        return maxm-minm;
    }
};