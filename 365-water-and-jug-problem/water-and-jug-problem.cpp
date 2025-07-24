class Solution {
private:
    bool measureWater(int a, int b, int x,int y, int target,vector<vector<bool>> &visited)
    {
        //explore all possibilities
        if(a==target || b==target || a+b==target)
            return true;
        if(visited[a][b])
            return false;
        visited[a][b] = true;
        if(measureWater(0, b, x, y, target, visited)) //empty jug1
            return true;
        if(measureWater(a, 0, x, y, target, visited)) //empty jug2
            return true;
        if(measureWater(x, b, x, y, target, visited)) //fill jug1
            return true;
        if(measureWater(a, y, x, y, target, visited)) //fill jug2
            return true;
            
        //transfer water from jug1 to jug2
        if(measureWater(max(0,a-(y-b)),min(y,a+b), x, y, target, visited))
            return true;

        //transfer water from jug2 to jug1
        if(measureWater(min(x,a+b),max(0,b-(x-a)), x, y, target, visited))
            return true;

        return false;        
    }
public:
    bool canMeasureWater(int x, int y, int target) 
    {
        vector<vector<bool>> visited(x+1,vector<bool>(y+1,false));
        return measureWater(x, y, x, y, target,visited);
    }
};