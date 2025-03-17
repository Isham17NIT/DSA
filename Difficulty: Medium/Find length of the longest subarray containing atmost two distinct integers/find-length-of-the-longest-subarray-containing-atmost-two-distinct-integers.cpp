//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) 
    {
        int maxLen=0;
        int l=0;
        unordered_map<int,int> s; //element : freq
        for(int r=0;r<arr.size();r++)
        {
            if(s.empty())
            {
                s[arr[r]]=1;
            }
            else if(s.find(arr[r])==s.end()) //distinct element
            {
                if(s.size()<2)
                {
                    s[arr[r]]=1;
                }
                else //s.size()==2
                {
                    //to find the next subarray satisfying the condn we need to find
                    //drop one distinct element
                    while(s.size()==2 && s.find(arr[l])!=s.end())
                    {
                        s[arr[l]]-=1;
                        if(s[arr[l]]==0)
                        {
                            s.erase(arr[l]);
                        }
                        l++;
                    }
                    s[arr[r]]=1;
                }
            }
            else
            {
                s[arr[r]]+=1;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
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
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends