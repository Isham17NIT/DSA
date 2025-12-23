class Solution {
private:
    int findLowerBound(int start, int end, int val, vector<vector<int>> &events)
    {
        int ans=-1;
        while(start <= end)
        {
            int mid = (start+end)>>1;
            if(events[mid][0] >= val)
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        int n=events.size();
        int ans=0;
        sort(events.begin(),events.end(),[](vector<int> &a, vector<int> &b){
            return a[0] < b[0]; // sort in asc based on start time
        });

        vector<int> maxValueSuffix(n,0);
        maxValueSuffix[n-1] = events[n-1][2];
        for(int i=n-2;i>=0;i--)
        {
            maxValueSuffix[i] = max(maxValueSuffix[i+1], events[i][2]);
        }

        for(int i=0;i<n;i++)
        {
            int j = findLowerBound(i+1, n-1, events[i][1] + 1, events);

            if(j==-1)
                ans = max(ans, events[i][2]);
            else
                ans = max(ans, events[i][2] + maxValueSuffix[j]);                
        }
        return ans;
    }
};