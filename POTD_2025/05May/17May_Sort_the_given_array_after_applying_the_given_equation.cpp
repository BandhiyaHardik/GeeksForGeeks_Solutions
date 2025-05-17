class Solution {
public:
    vector<int> sortArray(vector<int>& arr, int A, int B, int C) {
        vector<int> result;

        for (int& x : arr) {
            int ans = A * x * x + B * x + C;
            result.push_back(ans);
        }

        sort(result.begin(), result.end());

        return result;
    }
};