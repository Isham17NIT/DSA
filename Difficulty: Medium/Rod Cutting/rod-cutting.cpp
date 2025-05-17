//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution 
{
  public:
    int cutRod(vector<int> &price) 
    {
        int n=price.size();
        vector<int> prevRow(n+1);
        for(int i=0;i<=n;i++)
        {
            prevRow[i] = i*price[0];
        }
        
        for(int idx=1;idx<n;idx++)
        {
            vector<int> currRow(n+1);
            for(int len=0;len<=n;len++)
            {
                int notTake = prevRow[len];
                int take = INT_MIN;
                int rodLength = idx+1;
                if(rodLength <= len)
                    take = price[idx] + currRow[len-rodLength];
                    
                currRow[len] = max(take, notTake);
            }
            prevRow = currRow;
        }
        return prevRow[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends