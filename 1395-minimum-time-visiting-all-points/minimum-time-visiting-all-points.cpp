class Solution 
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int time = 0;
        vector<int> prev = points[0];
        for(int i=1;i<points.size();i++)
        {
            int x = points[i][0], y=points[i][1];
            while(prev[0] != x && prev[1] != y)
            {
                if(prev[0] < x && prev[1] < y){
                    prev[0] += 1;
                    prev[1] += 1;
                }
                else if(prev[0] < x && prev[1] > y){
                    prev[0] += 1;
                    prev[1] -= 1;
                }
                else if(prev[0] > x && prev[1] < y){
                    prev[0] -= 1;
                    prev[1] += 1;
                }   
                else{
                    prev[0] -= 1;
                    prev[1] -= 1;
                } 
                time++;            
            }
            time += abs(x-prev[0]) + abs(y-prev[1]);
            prev = points[i];
        }
        return time;
    }
};