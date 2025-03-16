class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        unordered_set<int> overlapping;

        // find the minm start and maxm end time in case the overlapping intervals exist
        int start=newInterval[0];
        int end=newInterval[1];

        for(int i=0;i<intervals.size();i++)
        {
            int start1=intervals[i][0];
            int end1=intervals[i][1];
            int start2=newInterval[0];
            int end2=newInterval[1];
            if(start1>end2)
                break;
            else if((start1<=start2 && end1>=start2) || (start2<=start1 && end2>=start1)) //overlapping interval
            {
                overlapping.insert(i); //index of overlapping interval
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
        }
        if(overlapping.size()==0) //no overlapping intervals were found
        {
            int i=0;
            while(i < intervals.size() && intervals[i][0] < newInterval[0])
            {
                i++;
            }
            intervals.insert(intervals.begin()+i,newInterval);
            return intervals;
        }
        //else
        for(int i=0;i<intervals.size();i++)
        {
            if(overlapping.find(i)==overlapping.end())
                ans.emplace_back(intervals[i]);
        }
        vector<int> merged={start,end};
        int i=0;
        while(i < ans.size() && ans[i][0] < merged[0])
        {
            i++;
        }
        ans.insert(ans.begin()+i,merged);
        return ans;
    }
};