class Solution 
{
private:
    void findLexicalOrder(int curr,int n,vector<int> &ans)
    {
        if(curr<=n)
            ans.push_back(curr);
        else
            return;
        for(int i=0;i<=9;i++)
        {
            findLexicalOrder(curr*10 + i,n,ans);
        }
        return;
    }
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            findLexicalOrder(i,n,ans);
        }
        return ans;
    }
};