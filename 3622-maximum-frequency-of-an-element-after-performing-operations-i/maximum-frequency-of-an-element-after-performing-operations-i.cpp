class Solution {
private:
    int findFreq(vector<int> &nums, int val)
    {
        auto it1=lower_bound(nums.begin(),nums.end(),val);
        auto it2=upper_bound(nums.begin(),nums.end(),val);
        return (it2-nums.begin()) - (it1-nums.begin());
    }
public:
    int maxFrequency(vector<int>& nums, int k, int numOps) 
    {
        int maxFreq=0;
        sort(nums.begin(),nums.end());
        for(int i=nums[0];i<=nums[nums.size()-1];i++)
        {
            auto it1=lower_bound(nums.begin(),nums.end(),i-k);
            auto it2=upper_bound(nums.begin(),nums.end(),i+k);

            //find number of elements in range [i-k, i+k]
            int numElements=(it2-nums.begin())-(it1-nums.begin());
            int currFreq=findFreq(nums, i);
            int reqOps=numElements-currFreq; //requiredOperations
            if(reqOps<=numOps)
                maxFreq=max(maxFreq, numElements);
            else
                maxFreq=max(maxFreq, numOps+currFreq);
        }
        return maxFreq;
    }
};