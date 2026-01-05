class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        int numNegative = 0, minVal=INT_MAX;
        long long sum=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] < 0)
                    numNegative+=1;
                
                sum+=(long long)abs(matrix[i][j]);
                minVal=min(minVal, abs(matrix[i][j]));
            }
        }
        if(numNegative%2==0)
            return sum;
        return sum-2*minVal;
    }
};