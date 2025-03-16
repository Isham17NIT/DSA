class Solution 
{
public:
    void insertAtCorrectPlace(vector<vector<int>> &arr,vector<int> &x)
    {
        int i=0;
        while(i < arr.size() && arr[i][0] < x[0])
        {
            i++;
        }
        arr.insert(arr.begin()+i,x); 
        return;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        unordered_set<int> overlapping; //stores indexes of intervals overlapping with newInterval

        // find the minm start and maxm end time in case of overlapping intervals so as to merge later
        int start=newInterval[0];
        int end=newInterval[1];

        for(int i=0;i<intervals.size();i++)
        {
            int start1=intervals[i][0];
            int end1=intervals[i][1];
            int start2=newInterval[0];
            int end2=newInterval[1];

            if(start1 > end2)
                break;
            else if((start1 <= start2 && end1 >= start2) || (start2 <= start1 && end2 >= start1)) //overlapping interval
            {
                overlapping.insert(i); 
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
        }

        if(overlapping.size()==0) //no overlapping intervals were found
        {
            insertAtCorrectPlace(intervals,newInterval);
            return intervals;
        }

        //else-->some overlapping intervals present
        for(int i=0;i<intervals.size();i++) //insert the non-overlapping intervals into ans
        {
            if(overlapping.find(i)==overlapping.end())
                ans.emplace_back(intervals[i]);
        }

        vector<int> merged={start,end};
        insertAtCorrectPlace(ans,merged);

        return ans;
    }
};