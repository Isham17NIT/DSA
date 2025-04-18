//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  private:
    vector<vector<pair<int,int>>> createGraph(int V,vector<vector<int>> &edges)
    {
        vector<vector<pair<int,int>>> graph(V,vector<pair<int,int>>());
        for(vector<int> e : edges)
        {
            graph[e[0]].push_back({e[1],e[2]});
        }
        return graph;
    }
    vector<int> getTopoSort(int src,vector<vector<pair<int,int>>> &graph,int V)
    {
        vector<int> topoSort;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(pair<int,int> p : graph[i])
            {
                indegree[p.first]+=1;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            topoSort.push_back(v);
            //reduce the indegree of its vertices
            for(pair<int,int> p : graph[v])
            {
                indegree[p.first]-=1;
                if(indegree[p.first]==0)
                    q.push(p.first);
            }
        }
        return topoSort;
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
    {
        vector<vector<pair<int,int>>> graph = createGraph(V,edges);
        vector<int> topoSort = getTopoSort(0,graph,V);
        vector<int> distance(V,INT_MAX);
        distance[0]=0;
        for(int i : topoSort)
        {
            //relax its edges
            for(pair<int,int> p : graph[i])
            {
                int dest = p.first;
                int wt = p.second;
                if(distance[i]!=INT_MAX && distance[dest] > distance[i] + wt) //relax
                    distance[dest] = distance[i] + wt;
            }
        }
        for(int i=0;i<V;i++)
        {
            if(distance[i]==INT_MAX)
                distance[i]=-1;
        }
        return distance;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends