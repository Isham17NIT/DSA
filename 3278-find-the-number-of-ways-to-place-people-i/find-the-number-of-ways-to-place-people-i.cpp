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
            for(int j=i+1;j<points.size();j++)
            {
                int x2=points[j][0], y2=points[j][1];
                if(x2>=x1 && y2<=y1)
                {
                    int c=0;
                    for(vector<int> p : points)
                    {
                        if((p[0]==x1 && p[1]==y1) || (p[0]==x2 && p[1]==y2))
                            continue;
                        else if(p[0]>=x1 && p[0]<=x2 && p[1]<=y1 && p[1]>=y2)
                            c+=1;
                    }
                    if(c==0) //valid pair
                        cnt+=1;
                }
            }
        }
        return cnt;
    }
};