class Solution 
{
private:
    int findMaxConsecutive(vector<int> &bars)
    {
        int ans=1;
        int i=0, j=1;
        while(j < bars.size())
        {
            if(bars[j]==bars[j-1]+1)
                j++;
            else{
                ans = max(j-i, ans);
                i = j;
                j++;
            }
        }
        ans = max(j-i, ans);
        return ans;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) 
    {
        sort(vBars.begin(), vBars.end()); //O(1) due to less size
        sort(hBars.begin(), hBars.end()); // O(1) due to less size
        int w = findMaxConsecutive(vBars);
        int h = findMaxConsecutive(hBars);
        int len = min(w+1,h+1);
        return len*len;
    }
};