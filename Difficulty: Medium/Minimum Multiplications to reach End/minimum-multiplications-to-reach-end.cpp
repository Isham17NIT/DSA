//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution 
{
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        vector<int> dist(100000,INT_MAX);
        int mod = 100000;
        
        queue<pair<int,int>> q; // steps : node
        q.push({0,start});
        dist[start]=0;
        
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            int steps = curr.first;
            int node = curr.second;
            if(node==end)
                break;
            for(int i : arr)
            {
                int neighbor = (node*i)%mod;
                if(dist[neighbor] > steps+1)
                {
                    dist[neighbor] = steps+1;
                    q.push({dist[neighbor], neighbor});
                }
            }
        }
        return dist[end]==INT_MAX ? -1 : dist[end];
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends