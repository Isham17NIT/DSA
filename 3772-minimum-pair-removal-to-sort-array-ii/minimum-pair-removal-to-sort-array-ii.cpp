class Solution 
{
public:
    int minimumPairRemoval(vector<int>& arr) 
    {

        int invCount = 0; //inversion count
        int n=arr.size();
        int minOps=0;

        vector<int> prevIdx(n);
        vector<int> nextIdx(n);
        vector<long long> nums(n);

        set<pair<long long,int>> sums;

        for(int i=0;i<n;i++)
        {
            prevIdx[i] = i-1;
            nextIdx[i] = i+1;
            if(i < n-1){
                if(arr[i] > arr[i+1])
                    invCount++;
                sums.insert({arr[i]+arr[i+1], i});
            }
            nums[i] = arr[i];
        }

        while(invCount > 0)
        {
            long long sum = sums.begin()->first;
            int first = sums.begin()->second;
            int second = nextIdx[first];

            int first_left = prevIdx[first];
            int second_right = nextIdx[second];

            sums.erase(sums.begin());

            if(nums[first] > nums[second])
                invCount--;

            if(first_left!=-1)
            {
                if(nums[first_left] > nums[first])
                    invCount--;
                if(nums[first_left] > sum)
                    invCount++;
                sums.erase({nums[first_left]+nums[first], first_left});
                sums.insert({nums[first_left] + sum, first_left});
            }
                
            if(second_right!=n)
            {
                if(nums[second] > nums[second_right])
                    invCount--;
                if(nums[second_right] < sum)
                    invCount++;
                sums.erase({nums[second]+nums[second_right], second});
                sums.insert({sum + nums[second_right], first});
                prevIdx[second_right] = first;
            }
                
            nextIdx[first] = second_right; 
                         
            nums[first] += nums[second];
            minOps++;
        }
        return minOps;
    }
};