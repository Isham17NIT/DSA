class Solution 
{
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int ans=0, n=seats.size();
        int leftClosest = -1;
        vector<int> rightClosest(n,-1);
    
        for(int i=n-1;i>=0;i--)
        {
            if(seats[i]==1)
                rightClosest[i]=i;
            else{
                if(i==n-1)
                    rightClosest[i]=INT_MAX;
                else
                    rightClosest[i]=rightClosest[i+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)  //occupied
            {
                leftClosest=i;
                continue;
            }
            int leftDis = leftClosest==-1 ? INT_MAX : i - leftClosest;
            int rightDis = rightClosest[i]==INT_MAX ? INT_MAX : rightClosest[i] - i;
            ans = max(ans, min(leftDis,rightDis));
        }
        return ans;
    }
};