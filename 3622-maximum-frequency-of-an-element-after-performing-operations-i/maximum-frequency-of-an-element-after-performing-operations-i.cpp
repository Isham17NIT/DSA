class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOps) 
    {
        int maxFreq=0, n=nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<int> freq(nums[n]+k+1,0);
        for(int i:nums)
        {
            freq[i]+=1;
        }
        //calculate cumulative frequencies
        for(int i=1;i<freq.size();i++)
        {
            freq[i]+=freq[i-1];
        }
        for(int i=nums[0];i<=nums[n];i++)
        {
            int l=i-k-1<0 ? 0 : freq[i-k-1];
            int r=freq[i+k];
            int numElements=r-l;
            int currFreq=i>0 ? freq[i]-freq[i-1] : freq[i];
            int reqOps=numElements-currFreq; //requiredOperations
            if(reqOps<=numOps)
                maxFreq=max(maxFreq, numElements);
            else
                maxFreq=max(maxFreq, numOps+currFreq);
        }
        return maxFreq;
    }
};