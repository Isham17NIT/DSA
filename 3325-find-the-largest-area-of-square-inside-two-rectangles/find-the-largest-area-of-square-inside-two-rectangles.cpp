class Solution {
private:
    long long getSquareIntersectionArea(vector<int> &bl1, vector<int> &tr1, vector<int> &bl2, vector<int> &tr2)
    {
        // Intersection rectangle coordinates

        int left   = max(bl1[0], bl2[0]);
        int right  = min(tr1[0], tr2[0]);
        int bottom = max(bl1[1], bl2[1]);
        int top    = min(tr1[1], tr2[1]);

        long long w = right - left;
        long long h = top - bottom;

        if (w <= 0 || h <= 0) return 0; // no overlap

        long long len = min(w, h);
        return len * len; 
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) 
    {
        long long maxArea=0;
        int n=bottomLeft.size(); // number of rectangles
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                maxArea = max(maxArea, getSquareIntersectionArea(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
            }
        }
        return maxArea;
    }
};