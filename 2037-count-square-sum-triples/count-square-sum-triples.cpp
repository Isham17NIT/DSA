class Solution {
public:
    int countTriples(int n) 
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int i_square=i*i;
            for(int j=1;j<i;j++)
            {
                int sum_left=i_square - j*j;
                double ceil_val = ceil(sqrt(sum_left));
                double floor_val = floor(sqrt(sum_left)); 
                if(int(ceil_val) == int(floor_val))
                    cnt++;
            }
        }
        return cnt;
    }
};