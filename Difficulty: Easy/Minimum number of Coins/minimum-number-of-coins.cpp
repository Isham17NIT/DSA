//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> currency={1,2,5,10,20,50,100,200,500,2000};
        vector<int> ans;
        
        for(int i=currency.size()-1;i>=0;i--)
        {
            if(currency[i]<=N)
            {
                int num=floor(N/currency[i]);
                for(int j=0;j<num;j++)
                {
                    ans.emplace_back(currency[i]);
                }
                N=N-num*currency[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends