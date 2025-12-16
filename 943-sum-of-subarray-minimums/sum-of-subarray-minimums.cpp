class Solution {
private:
    vector<int> findPrevSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int ans=0, n=arr.size();
        int mod=1e9+7;
        vector<int> pse=findPrevSmallerElement(arr);
        vector<int> nse=findNextSmallerElement(arr);
        for(int i=0;i<n;i++)
        {
            if(pse[i]==-1 && nse[i]==-1) //smallest element in the entire array
                ans = (ans + arr[i]*(i+1)*(n-i))%mod;
            else
            {
                int left = pse[i]==-1 ? i : i-pse[i]-1; //no. of elements on left of arr[i] which are >= arr[i]
                int right = nse[i]==-1 ? n-i-1 : nse[i]-i-1; //no. of elements on left of arr[i] which are >= arr[i]
                int total = left + right + 1;
                int j = i - (pse[i]+1); //posn of the element in the new subarray
                ans = ((long long)ans + (long long)arr[i]*(long long)(j+1)*(long long)(total-j))%mod;
            }
        }
        return ans%mod;
    }
};