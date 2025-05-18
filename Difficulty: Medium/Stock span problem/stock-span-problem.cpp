//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    vector<int> calculateSpan(vector<int>& arr) 
    {
        stack<int> s;
        vector<int> ans(arr.size());
        int i=0;
        while(i<arr.size())
        {
            while(!s.empty() && arr[i] >= arr[s.top()])
            {
                s.pop();
            }
            if(s.empty())
                ans[i]=i+1;
            else if(arr[i]<arr[s.top()])
            {
                ans[i]=i-s.top();
            }
            s.push(i);
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends