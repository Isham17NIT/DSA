class Solution 
{
private:
    int findMinCandidate(int x)
    {
        int pos=0; // LSB
        int temp = x;
        while(x > 0)
        {
            int bit=x&1;
            if(bit==0)
                break;
            x>>=1;
            pos++;
        }
        if(pos==0) // 0 present at the end
            return -1;

        pos-=1; // posn of 1st one after zero
        temp = temp & ~(1 << pos);
        return temp;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i] = findMinCandidate(nums[i]);
        }
        return ans;
    }
};