//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int findMinArrivalTime(vector<int> &arr)
    {
        int minm=INT_MAX;
        for(int i : arr)
        {
            minm = min(i, minm);
        }
        return minm;
    }
    int findMaxDepartureTime(vector<int> &dep)
    {
        int maxm=INT_MIN;
        for(int i : dep)
        {
            maxm=max(i,maxm);
        }
        return maxm;
    }
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) 
    {
        int minAtime = findMinArrivalTime(arr); //considering this as start point
        int maxDeptTime = findMaxDepartureTime(dep) - minAtime;
        
        int res=0, count=0;
        
        vector<int> v(maxDeptTime+2,0);
        int n=arr.size();
        
        for (int i = 0; i < n; i++) 
        {
            v[arr[i]-minAtime]++;
            v[dep[i]-minAtime + 1]--;
        }
        
        for (int i = 0; i <= maxDeptTime + 1; i++) 
        {
            count += v[i];
            res = max(res, count);
        }
    
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends