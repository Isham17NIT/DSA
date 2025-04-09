//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<vector<int>> createGraph(int v, vector<pair<int, int>>& edges)
    {
        vector<vector<int>> graph(v,vector<int>());
        for(pair<int,int> p : edges)
        {
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        return graph;
    }
    bool isValid(int node,int c,vector<int> &color,vector<int> neighbours)
    {
        for(int i : neighbours)
        {
            if(color[i]==c)
                return false;
        }
        return true;
    }
    bool isPossible(int node,int m,vector<vector<int>> &graph,vector<int> &color)
    {
        if(node==graph.size())
            return true;
        for(int i=0;i<m;i++)
        {
            if(isValid(node,i,color,graph[node]))
            {
                color[node]=i;
                if(isPossible(node+1,m,graph,color))
                    return true;
                color[node]=-1; //backtrack
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) 
    {
        vector<vector<int>> graph=createGraph(v,edges);
        vector<int> color(v,-1);
        return isPossible(0, m, graph, color);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends