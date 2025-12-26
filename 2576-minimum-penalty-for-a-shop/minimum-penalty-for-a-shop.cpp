class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n=customers.size(), minPenalty=INT_MAX, ans=-1;
        int total_Y=0, total_N=0, curr_Y=0, curr_N=0;
        for(char c : customers)
        {
            if(c=='Y')
                total_Y++;
        }
        total_N = n - total_Y;

        for(int j=0;j<=n;j++)
        {
            int penalty;
            if(j==0)
                penalty = total_Y;
            else if(j==n)
                penalty = total_N;
            else
                penalty = curr_N + (total_Y - curr_Y);
            if(penalty < minPenalty)
            {
                minPenalty = penalty;
                ans = j;
            }
            if(j<n)
            {
                if(customers[j]=='Y')
                    curr_Y++;
                else
                    curr_N++;
            }
        }
        return ans;
    }
};