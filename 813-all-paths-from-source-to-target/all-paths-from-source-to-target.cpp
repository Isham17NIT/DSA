class Solution 
{
private:
    void findAllPaths(int curr,vector<vector<int>>& graph,vector<bool> &visited,vector<int> currPath,vector<vector<int>> &allPaths)
    {
        if(curr==graph.size()-1) //dest 
        {
            allPaths.push_back(currPath);
            return;
        }
        visited[curr] = true;
        for(int neighbour : graph[curr])
        {
            if(!visited[neighbour])
            {
                currPath.push_back(neighbour);
                findAllPaths(neighbour,graph,visited,currPath,allPaths);
                currPath.erase(currPath.end());
            }
        }
        visited[curr] = false; //backtrack
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> allPaths;
        vector<bool> visited(graph.size(),false);
        findAllPaths(0,graph,visited,{0},allPaths);
        return allPaths;
    }
};