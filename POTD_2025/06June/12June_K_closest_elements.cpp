class Solution {
public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n   = arr.size();
        int pos = -1;

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] < x) {
                pos = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int left = pos, right = pos + 1;

        if (right < n && arr[right] == x) {
            right++;
        }

        vector<int> result;

        while (left >= 0 && right < n && result.size() < k) {
            int leftDiff  = abs(arr[left] - x);
            int rightDiff = abs(arr[right] - x);

            if (leftDiff < rightDiff) {
                result.push_back(arr[left]);
                left--;
            } else {
                result.push_back(arr[right]);
                right++;
            }
        }

        while (left >= 0 && result.size() < k) {
            result.push_back(arr[left]);
            left--;
        }

        while (right < n && result.size() < k) {
            result.push_back(arr[right]);
            right++;
        }

        return result;
    }
};