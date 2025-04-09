//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
private:
    void generateStrings(int idx,int num,string curr,vector<string> &ans,int prev)
    {
        if(idx==num)
        {
            ans.push_back(curr);
            return;
        }
        generateStrings(idx+1,num,curr+to_string(0),ans,0);
        if(prev==-1 || prev==0)
           generateStrings(idx+1,num,curr+to_string(1),ans,1); 
    }
public:
    vector<string> generateBinaryStrings(int num)
    {
        vector<string> ans;
        generateStrings(0,num,"",ans,-1);
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends