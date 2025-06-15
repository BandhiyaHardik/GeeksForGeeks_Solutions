class Solution {
public:

    bool valid(vector<int>& arr, int mid, int k) {
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += ceil((double)arr[i] / mid);
            if (sum > k) {
                return false;
            }
        }

        return sum <= k;
    }

    int smallestDivisor(vector<int>& arr, int k) {
        int low    = 1;
        int high   = *max_element(arr.begin(), arr.end());
        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (valid(arr, mid, k)) {
                result = mid;
                high   = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};