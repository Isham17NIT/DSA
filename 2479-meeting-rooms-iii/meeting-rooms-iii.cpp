class Solution {
private:
    int maxMeetingsRoom(vector<int> &numMeetings)
    {
        int ans=-1, maxMeetings=0;
        for(int i=0;i<numMeetings.size();i++)
        {
            if(numMeetings[i] > maxMeetings)
            {
                maxMeetings = numMeetings[i];
                ans = i;
            }
        }
        return ans;
    }
    struct Compare{
        bool operator()(pair<int,long long> &a, pair<int,long long> &b){
            if(a.second == b.second)
                return a.first > b.first; // tie-->smaller first has higher priority
            return a.second > b.second; // min heap by second
        }
    };
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        vector<int> numMeetings(n, 0);

        priority_queue<pair<int,long long>, vector<pair<int,long long>>, Compare> rooms;
        for(int i=0;i<n;i++)
        {
            rooms.push({i,0}); // room Number, time at which it is available earliest
        }

        sort(meetings.begin(), meetings.end()); //ascending order by start time

        for(vector<int> m : meetings)
        {
            pair<int,long long> r = rooms.top();
            rooms.pop();
            while(r.second < m[0]) //room available but meeting starts late
            {
                rooms.push({r.first, (long long)m[0]});
                r = rooms.top();
                rooms.pop();
            }
            numMeetings[r.first]+=1;
            rooms.push({r.first, r.second + m[1] - m[0]});
        }

        return maxMeetingsRoom(numMeetings);
    }
};