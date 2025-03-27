//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution 
{
  public:
    void dfsVisit(int i,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &nodes)
    {
        visited[i]=true;
        for(int n : adj[i])
        {
            if(!visited[n])
                dfsVisit(n, adj, visited, nodes);
        }
        nodes.push(i);
        return;
    }
    int kosaraju(vector<vector<int>> &adj) 
    {
        int n=adj.size();
        int cnt=0; //count of SCC
        
        vector<bool> visited(n,false);
        stack<int> nodes;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfsVisit(i,adj,visited,nodes);
        }
        
        fill(visited.begin(), visited.end(), false); // Set all to 'true'
        
        //reverse the edges of graph-->to avoid going into next SCC
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<n;i++)
        {
            for(int j : adj[i])
            {
                graph[j].push_back(i);
            }
        }
        
        //again apply DFS
        while(!nodes.empty())
        {
            int curr = nodes.top();
            nodes.pop();
            if(!visited[curr])
            {
                dfsVisit(curr,graph,visited,nodes);
                cnt++;
            }
        }
        return cnt;
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
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends