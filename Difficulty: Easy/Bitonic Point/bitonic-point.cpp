//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution 
{
  public:
    int findMaximum(vector<int> &arr) 
    {
        int n=arr.size();
        if(arr[0]>arr[1])
            return arr[0];
        if(arr[n-2]<arr[n-1])
            return arr[n-1];
            
        int low=1, high=n-2, ans=-1;
            
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                ans=arr[mid];
                break;
            }
            else if(arr[mid]>arr[mid-1])
                low=mid+1;
            else
                high=mid-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends