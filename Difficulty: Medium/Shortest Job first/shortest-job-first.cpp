//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

// Back-end complete function Template for C++

class Solution 
{
  public:
    long long solve(vector<int>& bt) 
    {
        long long waitingTime=0;
        int n=bt.size();
        sort(bt.begin(),bt.end());
        int time=0;
        for(int i=0;i<n;i++)
        {
            time+=bt[i];
            waitingTime+=(time-bt[i]);
        }
        return waitingTime/n;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends