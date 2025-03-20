class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int lSum=0, rSum=0, ans=INT_MIN, n=cardPoints.size();
        for(int i=0;i<k;i++){
            lSum+=cardPoints[i];
        }
        ans=max(lSum,0);
        for(int i=n-1;i>=n-k;i--)
        {
            lSum-=cardPoints[k-(n-i)];
            rSum+=cardPoints[i];
            ans=max(ans,lSum+rSum);
        }
        return ans;
    }
};