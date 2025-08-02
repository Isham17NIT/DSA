class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        for(int i=0;i<min(n,k);i++)
        {
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++)
        {
            pq.push(nums[i]);
            pq.pop();
        }
        return pq.top();
    }
};