class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        vector<vector<int>> ans;
        for(vector<int> i : points)
        {
            if(ans.empty())
                ans.push_back(i);
            else if(i[0]<=ans[ans.size()-1][1])
            {
                ans[ans.size()-1][0] = max(ans[ans.size()-1][0], i[0]);
                ans[ans.size()-1][1] = min(ans[ans.size()-1][1], i[1]);
            }
            else
                ans.push_back(i);
        }
        return ans.size();
    }
};