class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int n=citations.size();
        vector<int> counts(n+1,0); // 0 to n
        for(int i : citations)
        {
            if(i>n)
                counts[n]+=1;
            else
                counts[i]+=1;
        }
        int cnt=0;
        for(int i=n;i>=0;i--)
        {
            cnt+=counts[i];
            if(cnt>=i)
                return i;
        }
        return 0;
    }
};