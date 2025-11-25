class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
        int n=1;
        int cnt=1; //length of n
        unordered_set<int> s;
        while(n%k!=0)
        {
            if(s.find(n%k)!=s.end())
                return -1;
            s.insert(n%k);
            cnt++;
            n=((long long)n*(long long)10+1)%k;
        }
        return cnt;
    }
};