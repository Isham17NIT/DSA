class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int i=0, j=height.size()-1, maxArea=0;
        while(i<j)
        {
            maxArea=max(maxArea, (j-i)*min(height[j],height[i]));
            if(height[j]<=height[i])
                j--;
            else
                i++;
        }
        return maxArea;
    }
};