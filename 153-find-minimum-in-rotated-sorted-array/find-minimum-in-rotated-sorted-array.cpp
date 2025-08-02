class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            if (arr[mid] > arr[high]) {
                // Minimum is in the right half (exclude mid)
                low = mid + 1;
            } else {
                // Minimum is in the left half (include mid)
                high = mid;
            }
        }

        // low == high at the minimum element
        return arr[low];
    }
};
