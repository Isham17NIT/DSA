//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    int noOfWays(int m, int n, int x) 
    {
        vector<int> prevRow(x+1,0);
        prevRow[0]=1;
        
        for(int diceNo=1;diceNo<=n;diceNo++)
        {
            vector<int> currRow(x+1);
            currRow[0] = 0;
            for(int target=1;target<=x;target++)
            {
                int numWays=0;
                for(int face=1;face<=min(m,target);face++)
                {
                    numWays += prevRow[target-face];
                }
                currRow[target] = numWays;
            }
            prevRow = currRow;
        }
        return prevRow[x];
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        int m, n, x;
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends