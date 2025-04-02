class Solution {
private:
    vector<int> applyKahnsAlgo(vector<vector<int>> &graph)
    {
        vector<int> topoSort;
        vector<int> indegree(graph.size(),0);
        queue<int> q;
        for(vector<int> v : graph)
        {
            for(int i : v)
            {
                indegree[i] += 1;
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            topoSort.push_back(curr);
            for(int i : graph[curr])
            {
                if(indegree[i] > 0) 
                {
                    indegree[i]-=1;
                    if(indegree[i]==0)
                        q.push(i);
                }
            }
        }
        return topoSort;
    }   
    vector<vector<int>> createGraph(int n, vector<vector<int>> &edges)   
    {
        vector<vector<int>> graph(n,vector<int>());
        for(vector<int> e : edges)
        {
            graph[e[1]].push_back(e[0]);
        }
        return graph;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph = createGraph(numCourses, prerequisites);
        vector<int> order = applyKahnsAlgo(graph);
        if(order.size() < numCourses) //cycle detected
            return vector<int>();
        return order;
    }
};