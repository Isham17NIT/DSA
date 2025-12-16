class Solution 
{
private:
    vector<int> rightGreatestElement(vector<int> &height, int n)
    {
        vector<int> nge(n);
        nge[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            nge[i]=max(height[i],nge[i+1]);
        }
        return nge;
    }
    vector<int> leftGreatestElement(vector<int> &height, int n)
    {
        vector<int> pge(n,-1);
        pge[0]=height[0];
        for(int i=1;i<n;i++)
        {
            pge[i]=max(height[i],pge[i-1]);
        }
        return pge;
    }
public:
    int trap(vector<int>& height) 
    {
        int ans=0, n=height.size();
        vector<int> nge=rightGreatestElement(height, n);
        vector<int> pge=leftGreatestElement(height, n);

        for(int i=1;i<n-1;i++)
        {
            ans += (min(nge[i], pge[i]) - height[i]);
        }
        return ans;
    }
};