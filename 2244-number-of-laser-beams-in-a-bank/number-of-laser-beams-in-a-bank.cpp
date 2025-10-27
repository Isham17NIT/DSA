class Solution 
{
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int cnt=0, i=0, j=1;
        vector<int> deviceCnt(bank.size(),0);
        for(int k=0;k<bank.size();k++)
        {
            string s=bank[k];
            deviceCnt[k]=count(s.begin(), s.end(), '1');
        }
        while(j<bank.size())
        {
            if(deviceCnt[i]==0){
                i++;
                j=i+1;
            }
            else if(deviceCnt[j]==0)
                j++;
            else
            {
                cnt+=(deviceCnt[i]*deviceCnt[j]);
                i=j;
                j++;
            }
        }
        return cnt;
    }
};