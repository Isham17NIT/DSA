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
        prevRow[0] = 1;
        for(int i=1;i<=n;i++) //diceNo
        {
            vector<int> currRow(x+1);
            currRow[0] = 0;
            for(int j=1;j<=x;j++) //x
            {
               int ways=0;
               for(int k=1;k<=min(m,j);k++) //face no.
               {
                   ways += prevRow[j-k];
               }
               currRow[j]=ways;
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