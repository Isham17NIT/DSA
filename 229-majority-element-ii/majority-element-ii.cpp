class Solution 
{
public:
    vector<int> majorityElement(vector<int>& arr) 
    {
        vector<int> ans;
        int el1=INT_MIN, el2=INT_MIN;
        int cnt1=0, cnt2=0;
        for(int i=0;i<arr.size();i++)
        {
            if(cnt1==0 && arr[i]!=el2)
            {
                el1=arr[i];
                cnt1=1;
            }
            else if(cnt2==0 && arr[i]!=el1)
            {
                el2=arr[i];
                cnt2=1;
            }
            else if(arr[i]==el1)
                cnt1++;
            else if(arr[i]==el2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        //check whether elements are the majority elements or not
        cnt1=0, cnt2=0;
        for(int i : arr)
        {
            if(i==el1)
                cnt1++;
            else if(i==el2)
                cnt2++;
        }
        int mini = floor(arr.size()/3);
        if(cnt1>mini)
            ans.push_back(el1);
        if(cnt2>mini)
            ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};