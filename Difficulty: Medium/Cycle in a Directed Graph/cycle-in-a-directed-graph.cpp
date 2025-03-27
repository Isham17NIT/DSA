//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    int applyKahns(vector<vector<int>> &adj)
    {
        int cnt=0;
        vector<bool> visited(adj.size(),false);
        vector<int> indegree(adj.size(),0);
        
        stack<int> s;
        
        //compute indegree of each
        for(vector<int> v : adj)
        {
            for(int i : v)
            {
                indegree[i]+=1;
            }
        }
        for(int i=0;i<adj.size();i++)
        {
            if(indegree[i]==0)
            {
                s.push(i);
            }
        }
        
        
        while(!s.empty())
        {
            int curr=s.top();
            s.pop();
            visited[curr]=true;
            for(int i : adj[curr])
            {
                if(!visited[i])
                {
                    indegree[i]-=1;
                    if(indegree[i]==0)
                        s.push(i);
                }
            }
            cnt++;
        }
        return cnt;
    }
    bool isCyclic(vector<vector<int>> &adj) 
    {
        int n=adj.size(); //total no. of nodes
        int cnt = applyKahns(adj);
        return n != cnt;
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
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends