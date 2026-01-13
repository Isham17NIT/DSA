class Solution {
private:
    pair<double, double> findArea(double mid, vector<vector<int>>& squares)
    {
        double areaAbove = 0, areaBelow = 0;
        for(vector<int> &v : squares)
        {
            double len = v[2];
            double top = v[1] + v[2];
    
            if(v[1] + v[2] <= mid) //completely under the line
                areaBelow += (len * len);
            else if(v[1] >= mid) //completely above the line
                areaAbove += (len * len);
            else // overlapping
            {
                areaBelow += (len * (mid - v[1]));
                areaAbove += (len * (top - mid));
            }
        }
        return {areaBelow, areaAbove};
    }
public:
    double separateSquares(vector<vector<int>>& squares) 
    {
        double areaBelow=0.0, areaAbove=0.0, ans=0.0;
        const double eps = 1e-5;
        double low=INT_MAX, high=INT_MIN;

        for(vector<int> &v : squares)
        {
            low = min(low, (double)v[1]);
            high = max(high, double(v[1] + v[2]));
        }

        while(high-low > eps)
        {
            double mid = (low+high)/2.0;

            auto [areaBelow, areaAbove] = findArea(mid, squares);

            if(areaAbove <= areaBelow){
                ans = mid;
                high = mid;
            }
            else
                low = mid;
        }
        return ans;
    }
};