class Solution 
{
private:
    bool dfsVisit(int node,vector<vector<int>> &graph,vector<bool> &isSafe,vector<bool> &visited,vector<bool> &pathVisited)
    {
        visited[node] = true;
        if(graph[node].empty()) //terminal node
        {
            isSafe[node] = true;
            return false; //no cycle detected
        }
        pathVisited[node] = true;
        for(int i : graph[node])
        {
            if(!visited[i])
            {
                if(dfsVisit(i,graph,isSafe,visited,pathVisited)) //cycle detected
                    return true;
            }
            else if(pathVisited[i]) //condn of cycle
                return true;
        }
        isSafe[node] = true;
        pathVisited[node] = false;
        return false; //no cycle detected
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int v = graph.size();
    
        vector<bool> isSafe(v,false);
        vector<int> ans;
        vector<bool> visited(v,false);
        vector<bool> pathVisited(v,false);

        for(int i=0;i<v;i++)
        {
            if(!visited[i]) 
                dfsVisit(i,graph,isSafe,visited,pathVisited);
        }

        for(int i=0;i<v;i++)
        {
            if(isSafe[i])
                ans.push_back(i);
        }
        return ans;
    }
};