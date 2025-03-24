//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfsVisit(int v,vector<vector<int>>& adj,vector<bool> &visited,vector<int> &parent)
    {
        visited[v]=true;
        for(int n : adj[v])
        {
            if(!visited[n])
            {
                parent[n]=v;
                if(dfsVisit(n,adj,visited,parent))
                    return true;
            }
            else if(visited[n] && parent[v]!=n) //condn of cycle
                return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) 
    {
        int V=adj.size();
        vector<bool> visited(V,false);
        vector<int> parent(V,-1);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfsVisit(i,adj,visited,parent))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends