//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findXor(int n)
    {
        switch(n%4)
        {
            case 0: return n;
            case 1: return 1;
            case 2: return n+1;
        }
        return 0;
    }
    vector<int> findTwoElement(vector<int>& arr) 
    {
        vector<int> ans;
        int n=arr.size();
        
        int x1=findXor(n); //xor of all numbers from 1 to n
        for(int i : arr)
        {
            x1 ^= i; //xor all elements in the array
        }
        // now x1 represents xor of the numbers to be found out
        
        int pos = log2(x1 & (~(x1-1)));//position of rightmost set bit
        
        //dividing the numbers into 2 groups
        
        int x2=0, x3=0;
        for(int i=1;i<=n;i++)
        {
            if(i & (1 << pos))
                x2 ^= i;
            else
                x3 ^= i;
        }
        for(int i : arr)
        {
            if(i & (1 << pos))
                x2 ^= i;
            else
                x3 ^= i;
        }
        
        // x2 and x3 represent these numbers but we need to find out which one
        // is missing and which is repeating
        int cnt1=0,cnt2=0;
        for(int i : arr)
        {
            if(x2==i)
                cnt1++;
            else if(x3==i)
                cnt2++;
                
            if(cnt1==2) 
            {
                ans={x2,x3};
                break;
            }
            if(cnt2==2)
            {
                ans={x3,x2};
                break;
            }
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
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends