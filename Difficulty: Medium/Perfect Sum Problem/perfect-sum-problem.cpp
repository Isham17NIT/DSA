//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    int perfectSum(vector<int>& arr, int target) 
    {
        vector<int> prevRow(target+1,0);
        prevRow[0]=1;
        if(arr[0]<=target)
        {
            if(arr[0]==0)
                prevRow[0]=2;
            else
                prevRow[arr[0]]=1;
        }
        for(int i=1;i<arr.size();i++)
        {
            vector<int> curr(target+1,0);
            for(int j=0;j<=target;j++)
            {
                int pick = 0;
                if(arr[i]<=j)
                    pick = prevRow[j-arr[i]];
                //notPick
                int notPick = prevRow[j];
                curr[j] = pick + notPick;
            }
            prevRow=curr;
        }
        return prevRow[target];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends