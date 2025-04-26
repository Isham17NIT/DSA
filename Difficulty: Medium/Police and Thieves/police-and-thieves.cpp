//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution 
{
  public:
    int catchThieves(vector<char> &arr, int k) 
    {
        // Code here
        int n=arr.size();
        int cnt=0;
        int i=0, j=0;
        //i->posn of next policeman
        //j->posn of next thief
        while(i<n && j<n)
        {
            if(arr[i]=='P' && arr[j]=='T')
            {
                int d = abs(i-j);
                if(d<=k)
                {
                    cnt++;
                    i++;
                    j++;
                }
                else if(j<i)
                    j++;
                else if(i<j)
                    i++;
            }
            else if(arr[i]=='T')
                i++;
            else if(arr[j]=='P')
                j++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<char> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        char ch;
        while (ss >> ch) {
            arr.push_back(ch);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        cout << obj.catchThieves(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends