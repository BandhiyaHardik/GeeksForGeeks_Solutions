class Solution {
public:
    bool finish(vector<int>& arr, int mid, int k) {
        int hours = 0;

        for (int i = 0; i < arr.size(); i++) {
            hours += arr[i] / mid;
            if (arr[i] % mid != 0) {
                hours++;
            }
        }

        return hours <= k;
    }
    
    int kokoEat(vector<int>& arr, int k) {
        
        int low    = 1;
        int high   = *max_element(arr.begin(), arr.end());
        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (finish(arr, mid, k)) {
                result = mid;
                high   = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};