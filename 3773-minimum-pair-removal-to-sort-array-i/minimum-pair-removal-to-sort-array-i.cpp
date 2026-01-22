class Solution 
{
public:
    int minimumPairRemoval(vector<int>& nums) 
    {
        int inversionCount = 0, minOps=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] > nums[i+1])
                inversionCount += 1;
        }
        while(inversionCount > 0)
        {
            int startIdx=0, minSum = nums[0] + nums[1];
            for(int i=1;i<nums.size()-1;i++)
            {
                if(minSum > nums[i] + nums[i+1]){
                    startIdx=i;
                    minSum = nums[i] + nums[i+1];
                }
            }
            if(nums[startIdx] > nums[startIdx+1])
                inversionCount--;
            if(startIdx!=0 && nums[startIdx] < nums[startIdx-1])
                inversionCount--;
            if(startIdx+1 < nums.size()-1 && nums[startIdx+1] > nums[startIdx+2])
                inversionCount--;

            nums[startIdx] = minSum;
            nums.erase(nums.begin() + startIdx + 1);

            // update inversion counts
            if(startIdx!=0 && nums[startIdx] < nums[startIdx-1])
                inversionCount++;
            if(startIdx+1 < nums.size() && nums[startIdx] > nums[startIdx+1])
                inversionCount++;

            minOps++;
        }
        return minOps;
    }
};