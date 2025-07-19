class Solution {
public:
    string simplifyPath(string path) 
    {
        stringstream ss(path);
        string token="", ans="";
        stack<string> s;
        while(getline(ss,token,'/'))
        {
            if(token!="" && token!="." && token!="..")
                s.push(token);
            else if(token==".." && !s.empty())
                s.pop();
        }
        while(!s.empty())
        {
            ans = '/' + s.top() + ans;
            s.pop();
        }
        return ans=="" ? "/" : ans;
    }
};