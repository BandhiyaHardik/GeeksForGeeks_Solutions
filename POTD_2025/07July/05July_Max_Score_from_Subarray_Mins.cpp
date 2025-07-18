class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n      = arr.size();
        int result = arr[0] + arr[1];
        
        for (int i = 1; i < n - 1; i++) {
            result = max(result, arr[i] + arr[i + 1]);
        }

        return result;
    }
};