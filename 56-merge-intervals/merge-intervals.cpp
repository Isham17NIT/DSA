class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        while(i < n)
        {
            if(ans.empty())
            {
                ans.emplace_back(intervals[i]);
                i++;
                continue;
            }
            if(intervals[i][0]<=ans[ans.size()-1][1]) //can be merged
            {
                while(i<n && intervals[i][0] <= ans[ans.size()-1][1])
                {
                    //merge
                    ans[ans.size()-1][0]=min(ans[ans.size()-1][0],intervals[i][0]);
                    ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
                    i++;
                }
            }
            else //can't be merged
            {
                ans.emplace_back(intervals[i]);
                i++;
            } 
        }
        return ans;
    }
};