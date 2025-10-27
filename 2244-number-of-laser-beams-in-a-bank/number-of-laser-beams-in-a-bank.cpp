class Solution 
{
private:
    int countDevices(string s)
    {
        int cnt=0;
        for(char c : s)
        {
            if(c=='1')
                cnt++;
        }
        return cnt;
    }
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int cnt=0, i=0, j=1;
        vector<int> deviceCnt(bank.size(),0);
        for(int k=0;k<bank.size();k++)
        {
            deviceCnt[k]=countDevices(bank[k]);
        }
        while(j<bank.size())
        {
            if(deviceCnt[i]==0){
                i++;
                j=i+1;
            }
            else if(deviceCnt[j]==0)
                j++;
            else{
                cnt+=(deviceCnt[i]*deviceCnt[j]);
                i=j;
                j++;
            }
        }
        return cnt;
    }
};