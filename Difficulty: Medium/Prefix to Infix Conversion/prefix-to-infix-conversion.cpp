//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution 
{
  private:
    bool isOperator(char c)
    {
        return c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%';
    }
  public:
    string preToInfix(string pre_exp) 
    {
        stack<string> s;
        for(int i=pre_exp.size()-1;i>=0;i--)
        {
            char c = pre_exp[i];
            if(isOperator(c))
            {
                string str = "(";
                string s1 = s.top();
                s.pop();
                string s2 = s.top();
                s.pop();
                
                str+=s1;
                str+=string(1,c);
                str+=s2;
                str+=")";
                s.push(str);
            }
            else
                s.push(string(1,c));
        }
        string ans=s.top();
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends