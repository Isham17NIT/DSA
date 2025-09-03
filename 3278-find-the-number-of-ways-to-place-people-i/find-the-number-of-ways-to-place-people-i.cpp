class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {
        int cnt=0;
        sort(points.begin(),points.end(),[](vector<int> &a, vector<int> &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        for(int i=0;i<points.size();i++)
        {
            int x1=points[i][0], y1=points[i][1];
            int maxY=INT_MIN;
            for(int j=i+1;j<points.size();j++)
            {
                int x2=points[j][0], y2=points[j][1];
                if(y2>y1)
                    continue;
                if(maxY==INT_MIN || y2>maxY)
                    cnt++;
                maxY=max(maxY,y2);
            }
        }
        return cnt;
    }
};