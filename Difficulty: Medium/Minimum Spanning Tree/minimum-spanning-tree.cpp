//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    struct Edge
    {
        int src,dest,wt;
        Edge(int s,int d,int w)
        {
            src=s;
            dest=d;
            wt=w;
        }
    };
    struct Compare
    {
        bool operator()(Edge e1, Edge e2)
        {
            return e1.wt < e2.wt; //sort in ascending order by edge weight
        }
    };
    int findParent(int parent[],int x)//finds ultimate parent
    {
        if(x==parent[x])
            return x;
        return parent[x] = findParent(parent,parent[x]);
    }
    void findUnion(int u,int v,int pu,int pv,int parent[],int rank[])
    {
        int ru = rank[pu];
        int rv = rank[pv];
        if(ru==rv)
        {
            rank[pu]+=1;
            parent[pv]=pu;
        }
        else if(ru > rv)
        {
            parent[pv]=pu;
        }
        else
        {
            parent[pu]=pv;
        }
        return;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) 
    {
        //union by rank
        int parent[V];
        int rank[V];
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
        vector<Edge> edges;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                edges.push_back(Edge(i,adj[i][j][0],adj[i][j][1]));
            }
        }
        sort(edges.begin(),edges.end(),Compare());
        
        int mst_weight=0;
        for(Edge e : edges)
        {
            int u=e.src;
            int v=e.dest;
            int pu=findParent(parent,u);
            int pv=findParent(parent,v);
            if(pu!=pv)
            {
                findUnion(u,v,pu,pv,parent,rank);
                mst_weight += e.wt;
            }
        }
        return mst_weight;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends