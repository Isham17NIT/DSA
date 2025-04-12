//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
    public:
        int minCost(vector<int>& height) 
        {
            int n=height.size();
            if(n==1)
                return 0;
            //base case
            int prev2=0;
            int prev1=abs(height[1]-height[0]);
            for(int i=2;i<n;i++)
            {
                int one = abs(height[i]-height[i-1]) + prev1;
                int two = abs(height[i]-height[i-2]) + prev2;
                int curr=min(one,two);
                
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends