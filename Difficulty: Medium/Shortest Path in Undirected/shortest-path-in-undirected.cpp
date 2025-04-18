//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution 
{
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& graph, int src) 
    {
        int V=graph.size();
        
        vector<int> distance(V,-1);
        vector<bool> visited(V,false);
        
        queue<int> q;
        
        visited[src]=true;
        distance[src]=0;
        q.push(src);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int neighbour : graph[curr])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    distance[neighbour] = distance[curr] + 1;
                    q.push(neighbour);
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends