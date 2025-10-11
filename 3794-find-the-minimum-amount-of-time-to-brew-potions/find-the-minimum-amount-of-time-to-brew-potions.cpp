class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(), m=mana.size();
        vector<long long> prevTime(n);

        // computing for the first potion
        prevTime[0]=skill[0]*mana[0];
        for(int i=1;i<n;i++)
        {
            prevTime[i]=prevTime[i-1]+skill[i]*mana[0];
        }
        // computation for rest of the potions
        for(int i=1;i<m;i++) // potions
        {
            vector<long long> finishTime = vector<long long>(n);
            finishTime[0] = skill[0]*mana[i] + prevTime[0];
            for(int j=1;j<n;j++) // wizards
            {
                finishTime[j] = (skill[j]*mana[i]) + max(prevTime[j], finishTime[j-1]);
            }
            for(int j=n-2;j>=0;j--)
            {
                finishTime[j] = finishTime[j+1] - (skill[j+1]*mana[i]);
            }
            prevTime = finishTime;
        }
        return prevTime[n-1];        
    }
};