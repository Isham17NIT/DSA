class Solution 
{
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int ans=0, n=seats.size();
        vector<int> leftClosest(n,-1);
        vector<int> rightClosest(n,-1);
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
                leftClosest[i]=i;
            else{
                if(i==0)
                    leftClosest[i]=INT_MAX;
                else
                    leftClosest[i]=leftClosest[i-1];
            }
        }
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
                continue;
            int leftDis = leftClosest[i]==INT_MAX ? INT_MAX : i - leftClosest[i];
            int rightDis = rightClosest[i]==INT_MAX ? INT_MAX : rightClosest[i] - i;
            ans = max(ans, min(leftDis,rightDis));
        }
        return ans;
    }
};