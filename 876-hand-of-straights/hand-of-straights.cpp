class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if(hand.size()%groupSize!=0)
            return false;

        map<int,int> m;
        for(int i : hand)
        {
            m[i]+=1;
        }
        
        while(m.size() >= groupSize)
        {
            auto it = m.begin();
            int start = it->first;
            int freq  = it->second;

            m.erase(m.begin());

            for(int i=1;i<groupSize;i++)
            {
                if(m.find(start+i)==m.end() || m[start+i] < freq)
                    return false;
                if(m[start+i] > freq)
                    m[start+i] -= freq;
                else// m[it.first+1] == it.second
                    m.erase(start+i); //erase by key
            }
        }
        return m.empty();
    }
};