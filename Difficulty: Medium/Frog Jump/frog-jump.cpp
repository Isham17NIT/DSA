class Solution {
  public:
    int minCost(vector<int>& height) 
    {
        // Code here
        int n=height.size();
        if(n==1)
            return 0;
        int prev1=abs(height[1]-height[0]);
        int prev2=0;
        for(int idx=2;idx<n;idx++)
        {
            int oneStep=prev1+abs(height[idx]-height[idx-1]);
            int twoSteps=prev2+abs(height[idx]-height[idx-2]);
            int curr=min(oneStep, twoSteps);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};










