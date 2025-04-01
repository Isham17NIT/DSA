//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  private:
    struct Compare
    {
        bool operator()(pair<int,int> &p1, pair<int,int> &p2)
        {
            return p1.second > p2.second; //lesser distance has more priority
        }
    };
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) 
    {
        int n=adj.size();
        
        vector<int> dist(n,INT_MAX);
        vector<bool> visited(n, false);
        dist[src]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, Compare> pq;
        
        pq.push({src, 0});
        for(int i=1;i<n;i++)
        {
            pq.push({i, INT_MAX});
        }
        
        while(!pq.empty())
        {
            pair<int,int> curr = pq.top();
            pq.pop();
            if(!visited[curr.first])
            {
                for(pair<int,int> p: adj[curr.first])
                {
                    visited[curr.first]=true;
                    if(!visited[p.first])
                    {
                        if(dist[curr.first] + p.second < dist[p.first]) //relaxation cond
                        {
                            dist[p.first] = dist[curr.first] + p.second;
                            //push it into the priority queue
                            pq.push({p.first, dist[p.first]});
                        }
                    }
                }
            }
        }
        return dist;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends