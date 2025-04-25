//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
  public:
    long long int PowMod(long long int a, long long int b, long long int m) 
    {
        if(a > m)
            a = a%m;
        if(a==0) //a was completely divisible by m
            return 0;
        long long int ans = 1;
        while(b > 0)
        {
            if(b&1) // b is odd
            {
                ans = (ans * a)%m;
                b-=1;
            }
            else
            {
                a = (a*a) % m;
                b = b >> 1;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends