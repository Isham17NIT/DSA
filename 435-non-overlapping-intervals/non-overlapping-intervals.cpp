class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),[](vector<int> &i1,vector<int> &i2){
            if(i1[1]==i2[1])
                return i1[0]>i2[0];
            return i1[1]<i2[1]; 
        });
        int cnt=1; 
        //to find out the minm no. of intervals to be removed, find the maxm no. of
        //non-overlapping intervals--->similar to N meetings in a room
        int time=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=time) //can be scheduled
            {
                cnt++;
                time=intervals[i][1];
            }
        }
        return intervals.size()-cnt;       
    }
};