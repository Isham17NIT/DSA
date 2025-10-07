class Solution {
private:
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> prev(n,-1);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,-1);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0){
                    curr[j]=1;
                    continue;
                }
                int up=isValid(i-1,j,m,n) ? prev[j] : 0;
                int left=isValid(i,j-1,m,n) ? curr[j-1] : 0;
                curr[j]=up+left;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};