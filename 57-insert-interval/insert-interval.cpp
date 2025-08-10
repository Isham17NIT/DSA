class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        int i=0;
        while(i < intervals.size() && intervals[i][0] <= newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        if(!ans.empty() && newInterval[0] <= ans[ans.size()-1][1]) //can be merged
        {
            ans[ans.size()-1][0] = min(ans[ans.size()-1][0], newInterval[0]);
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1], newInterval[1]);
        }
        else //can't be merged
            ans.push_back(newInterval);
        while(i < intervals.size())
        {
            if(intervals[i][0] <= ans[ans.size()-1][1]) //can be merged
            {
                ans[ans.size()-1][0] = min(ans[ans.size()-1][0], intervals[i][0]);
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
            else
                ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};