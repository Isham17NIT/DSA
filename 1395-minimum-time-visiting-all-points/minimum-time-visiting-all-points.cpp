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
            int dis = min(abs(prev[0]-x), abs(prev[1]-y));
            if(prev[0] < x && prev[1] < y){
                prev[0]+=dis;
                prev[1]+=dis;
            }          
            else if(prev[0] < x && prev[1] > y){
                prev[0] += dis;
                prev[1] -= dis;
            }
            else if(prev[0] > x && prev[1] < y){
                prev[0] -= dis;
                prev[1] += dis;
            }   
            else if(prev[0] > x && prev[1] > y){
                prev[0] -= dis;
                prev[1] -= dis;
            }
            time+=abs(dis);
            time += abs(x-prev[0]) + abs(y-prev[1]);
            prev = points[i];
        }
        return time;
    }
};