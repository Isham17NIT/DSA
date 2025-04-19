class Solution 
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int v=graph.size();

        vector<bool> isSafe(v,false);
        vector<int> indegree(v,0);
        vector<int> ans;
        vector<vector<int>> revGraph(v,vector<int>());
        for(int i=0;i<v;i++)
        {
            for(int j : graph[i])
            {
                revGraph[j].push_back(i);
            }
        }
        //compute indegrees
        for(int i=0;i<v;i++)
        {
            for(int j : revGraph[i])
            {
                indegree[j]+=1;
            }
        }
        
        queue<int> q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            isSafe[curr] = true;
            for(int j : revGraph[curr])
            {
                indegree[j]-=1;
                if(indegree[j]==0)
                    q.push(j);
            }
        }
        for(int i=0;i<v;i++)
        {
            if(isSafe[i])
                ans.push_back(i);
        }
        return ans;
    }
};