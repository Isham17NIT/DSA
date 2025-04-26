//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends

class Solution {
  public:
    long long maxSum(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        vector<int> nums;
        int n=arr.size();
        int i=0, j=n-1;
        while(i<j)
        {
            nums.push_back(arr[i++]);
            nums.push_back(arr[j--]);
        }
        if(n&1) // to handle middle element in case of odd length array
        {
            nums.push_back(arr[i]);
        }
        int ans = 0;
        for(i=1;i<n;i++)
        {
            ans += abs(nums[i]-nums[i-1]);
        }
        ans += abs(nums[n-1]-nums[0]);
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends