//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    vector<long long> maxMinProduct(vector<int>& arr) 
    {
        long long maxProduct = arr[0];
        long long minProduct = arr[0];
        long long prevMaxProduct = arr[0];
        long long prevMinProduct = arr[0];
        long long currMaxProduct = arr[0];
        long long currMinProduct = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            currMaxProduct = max(prevMaxProduct * arr[i], prevMinProduct * arr[i]);
            currMaxProduct = max(currMaxProduct, prevMaxProduct);
            currMaxProduct = max(currMaxProduct, (long long)arr[i]);
            maxProduct = max(maxProduct, currMaxProduct);
            
            currMinProduct = min(prevMaxProduct * arr[i], prevMinProduct * arr[i]);
            currMinProduct = min(currMinProduct, prevMinProduct);
            currMinProduct = min(currMinProduct, (long long)arr[i]);
            minProduct = min(minProduct, currMinProduct);
            
            prevMaxProduct = currMaxProduct;
            prevMinProduct = currMinProduct;
        }
        return {maxProduct, minProduct};
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To consume any newline character left in the input buffer
    Solution obj;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        vector<long long> result = obj.maxMinProduct(arr);
        cout << result[0] << " " << result[1] << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends