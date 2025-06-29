class Solution {
public:
    bool check(int mid, vector<int>& arr, int k) {
        int n = arr.size();

        int count = 1;
        int sum   = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                return false;
            }

            sum += arr[i];

            if (sum > mid) {
                count++;
                sum = arr[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();

        int low  = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(mid, arr, k)) {
                result = mid;
                high   = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};