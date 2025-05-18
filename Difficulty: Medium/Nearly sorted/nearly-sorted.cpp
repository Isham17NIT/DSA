//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    void nearlySorted(vector<int>& arr, int k) 
    {
        int n=(int)arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        //insert first k elements
        for(int i=0;i<min(n,k);i++)
        {
            pq.push(arr[i]);
        }
        if(n<=k)
        {
            int i=0;
            while(!pq.empty())
            {
                arr[i]=pq.top();
                pq.pop();
                i++;
            }
            return;
        }
        int j=0;
        for(int i=k;i<n;i++)
        {
            pq.push(arr[i]);
            arr[j++]=pq.top();
            pq.pop();
        }
        while(!pq.empty())
        {
            arr[j++]=pq.top();
            pq.pop();
        }
        return;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends