class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < k; i++) {
            pq.push({arr[i][0], i, 0});
            maxi = max(maxi, arr[i][0]);
        }
        int start = 0, end = 1e5;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            mini = curr[0];
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (curr[2] + 1 < arr[curr[1]].size()) {
                pq.push({arr[curr[1]][curr[2] + 1], curr[1], curr[2] + 1});
                maxi = max(maxi, arr[curr[1]][curr[2] + 1]);
            } else {
                break;
            }
        }
        return {start, end};
    }
};