class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i=0, j=height.size()-1;
        int ans=0;
        while(i<j)
        {
            int h1=height[i], h2=height[j];
            ans = max(ans,min(h1,h2)*(j-i));
            if(h1<=h2)
                i++;
            else
                j--;
        }
        return ans;
    }
};