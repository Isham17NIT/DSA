class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int cnt=0, time=0;
        unordered_map<char, int> m;
        for(char c : tasks)
        {
            m[c]+=1;
        }
        priority_queue<int> pq; //max heap by default

        for(auto &it : m)
        {
            pq.push(it.second);
        }

        while(!pq.empty())
        {
            int cycle=n+1;
            vector<int> store;
            int taskCount=0;
            //execute tasks in each cycle
            while(cycle>0 && !pq.empty())
            {
                if(pq.top() > 1)
                    store.push_back(pq.top()-1);
                pq.pop();
                taskCount++;
                cycle--;
            }
            //restore updated freq to the heap
            for(int &x : store){
                pq.push(x);
            }
            time+= (pq.empty() ? taskCount : n+1);
        }
        return time;
    }
};