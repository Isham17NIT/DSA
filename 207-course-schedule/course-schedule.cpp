class Solution 
{
public:
    bool dfsVisit(int v,vector<vector<int>>& graph,vector<bool> &visited,vector<bool> &recStack)
    {
        visited[v]=true;
        recStack[v]=true;
        for(int n : graph[v])
        {
            if(!visited[n])
            {
                if(dfsVisit(n,graph,visited,recStack))
                    return true;
            }
            else if(recStack[n])
                return true;
        }
        recStack[v]=false; //traversed fully
        return false; //no cycle
    }
    bool canFinish(int numOfCourses, vector<vector<int>>& prerequisites) 
    {
        vector<bool> visited(numOfCourses,false);
        vector<bool> recStack(numOfCourses,false);
        vector<vector<int>> graph(numOfCourses,vector<int>());

        for(vector<int> v : prerequisites)
        {
            int a = v[0];
            int b = v[1];
            graph[b].push_back(a);
        }

        for(int i=0;i<numOfCourses;i++)
        {
            if(!visited[i])
            {
                if(dfsVisit(i,graph,visited,recStack)) //cycle detected
                    return false; //not able to finish courses
            }
        }
        return true;
    }
};