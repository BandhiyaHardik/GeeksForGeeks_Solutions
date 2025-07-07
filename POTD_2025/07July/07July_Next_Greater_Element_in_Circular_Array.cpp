class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int         n = arr.size();
        vector<int> result(n, -1);
        stack<int>  st;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            int num = arr[idx];

            while (!st.empty() && num > arr[st.top()]) {
                result[st.top()] = num;
                st.pop();
            }

            if (i < n) {
                st.push(idx);
            }
        }
        return result;
    }
};