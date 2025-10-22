class Solution 
{
public:
    string findLexSmallestString(string str, int a, int b) 
    {
        int n=str.size();
        string ans=str;
        set<string> visited; //to keep track of visited states
        queue<string> q;
        q.push(str);
        while(!q.empty())
        {
            string curr=q.front();
            q.pop();
            ans=min(ans, curr);
            string rotatedStr=curr.substr(n-b)+curr.substr(0,n-b);
            if(visited.find(rotatedStr)==visited.end())
            {
                q.push(rotatedStr);
                visited.insert(rotatedStr);
            }
            for(int i=1;i<n;i+=2)
            {
                curr[i]=(curr[i]-'0'+a)%10 + '0';
            }
            if(visited.find(curr)==visited.end())
            {
                q.push(curr);
                visited.insert(curr);
            }
        }
        return ans;
    }
};