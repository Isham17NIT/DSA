//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    int minCoins(vector<int> &coins, int sum) 
    {
        int n=coins.size();
        vector<int> prevRow(sum+1);
        //initialise base case
        prevRow[0]=0;
        for(int j=1;j<=sum;j++)
        {
            if(j%coins[0]!=0) // not possible to cover amt
                prevRow[j] = (int)1e9;
            else
                prevRow[j] = j/coins[0];
        }
        
        for(int i=1;i<n;i++)
        {
            vector<int> currRow(sum+1);
            currRow[0] = 0;
            for(int j=1;j<=sum;j++)
            {
                //pick
                int pick = (int)1e9;
                if(coins[i] <= j)
                    pick = 1 + currRow[j-coins[i]];
                //not pick
                int notPick = prevRow[j];
                currRow[j] = min(pick, notPick);
            }
            prevRow = currRow;
        }
        return prevRow[sum] >= (int)1e9 ? -1 : prevRow[sum];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends