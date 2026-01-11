class Solution {
private:
    vector<int> findNSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, -1);
        stack<int> st; // stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                pse[i] = st.top();

            st.push(i);
        }
        return pse;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> intMatrix(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                intMatrix[i][j] = matrix[i][j] - '0';
            }
        }
        vector<int> row(m, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(intMatrix[i][j]==0)
                    row[j] = 0;
                else
                    row[j]+=1;
            }
            vector<int> nse = findNSE(row);
            vector<int> pse = findPSE(row);
            for(int j=0;j<m;j++)
            {
                int area;
                if(nse[j]==-1 && pse[j]==-1)
                    area = row[j] * m;
                else if(nse[j]==-1)
                    area = row[j] * (m-pse[j]-1);
                else if(pse[j]==-1)
                    area = row[j] * nse[j];
                else
                    area = row[j] * (nse[j] - pse[j] - 1);
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;                
    }
};