class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        int ans=0;
        priority_queue<int> pq; //max heap
        for(int i : amount)
        {
            if(i>0)
                pq.push(i);
        }
        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            if(pq.empty())
                return ans + x;
            int y = pq.top();
            pq.pop();
            if(x>1)
                pq.push(x-1);
            if(y>1)
                pq.push(y-1);
            ans++;
        }
        return ans;
    }
};