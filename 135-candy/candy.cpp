class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        vector<int> left(n);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
            else
                left[i]=1; //greedily assign the minm possible
        }
        int candies=0;
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                left[i]=max(left[i],left[i+1]+1);
            candies+=left[i];
        }
        candies+=left[n-1];
        return candies;
    }
};