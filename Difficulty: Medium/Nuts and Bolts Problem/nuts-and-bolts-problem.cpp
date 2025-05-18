//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution 
{
  private:
    int parition(char bolts[], int start, int end, char pivot)
    {
        int i=start-1; //initially i list is empty
        for(int j=start;j<end;j++)
        {
            if(bolts[j] < pivot)
            {
                i++;
                int temp = bolts[j];
                bolts[j] = bolts[i];
                bolts[i] = temp;
            }
            else if(bolts[j]==pivot)
            {
                // take bolts[j] to last
                int temp = bolts[j];
                bolts[j] = bolts[end];
                bolts[end] = temp;
                j--;
            }
        }
        int temp = bolts[end];
        bolts[end] = bolts[i+1];
        bolts[i+1] = temp;
        return i+1;
    }
    void matchNutsBolts(char nuts[],char bolts[],int start,int end)
    {
        if(start < end)
        {
            int pivotIdx = end;
            int idx = parition(bolts, start, end, nuts[pivotIdx]);
            parition(nuts, start, end, bolts[idx]);
            
            matchNutsBolts(nuts,bolts,start,idx-1);
            matchNutsBolts(nuts,bolts,idx+1,end);
        }
        return;
    }
  public:
    void matchPairs(int n, char nuts[], char bolts[]) 
    {
        matchNutsBolts(nuts,bolts,0,n-1);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends