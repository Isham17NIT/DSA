class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int openCnt=0, closeCnt=0;
        for(char c : s)
        {
            if(c=='(')
                openCnt++;
            else
            {
                if(openCnt==0)
                    closeCnt+=1;
                else
                    openCnt--;
            }
        }
        return openCnt+closeCnt;
    }
};