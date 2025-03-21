//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsVisit(vector<vector<int>>& adj,int i,vector<int> &ans,vector<bool> &visited)
    {
        visited[i]=true;
        ans.emplace_back(i);
        for(int n : adj[i])
        {
            if(!visited[n])
            {
                dfsVisit(adj,n,ans,visited);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) 
    {
        vector<bool> visited(adj.size(),false);
        vector<int> ans;
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
                dfsVisit(adj,i,ans,visited);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends