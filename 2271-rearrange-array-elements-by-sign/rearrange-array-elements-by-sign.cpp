class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        int pos_idx=0, neg_idx=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0){
                ans[pos_idx]=nums[i];
                pos_idx+=2;
            }
            else{
                ans[neg_idx]=nums[i];
                neg_idx+=2;
            }
        }
        return ans;
    }
};