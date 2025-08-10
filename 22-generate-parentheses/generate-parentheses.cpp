class Solution 
{
private:
    void generateValidParenthesis(int idx,int n,string curr,vector<string> &ans,int openCnt, int closeCnt)
    {
        if(idx==2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(openCnt < n)
            generateValidParenthesis(idx+1,n,curr+'(',ans,openCnt+1, closeCnt);
        if(openCnt > closeCnt) //then only we can put close bracket
            generateValidParenthesis(idx+1,n,curr+')',ans,openCnt, closeCnt+1);
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        generateValidParenthesis(0,n,"",ans,0,0);
        return ans;
    }
};