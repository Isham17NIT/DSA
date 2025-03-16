class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        int sum=1; //first child will be assigned 1 candy
        int i=1;
        int n=ratings.size();
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                sum+=down;
                down++;
                i++;
            }
            sum = sum - peak + max(peak,down);
        }
        return sum;
    }
};