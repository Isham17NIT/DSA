class Solution {
private:
    bool isPossibleToReach(int speed, double hour, vector<int> &dist)
    {
        double time = 0;
        for(int i=0;i<dist.size()-1;i++)
        {
            time += ceil((double)dist[i]/(double)speed);
        }
        // for the last train we'll use the exact time
        time += (double)dist[dist.size()-1]/(double)speed;
        return time <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int low=1, high=1e7, ans=-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(isPossibleToReach(mid, hour, dist))
            {
                ans = mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};