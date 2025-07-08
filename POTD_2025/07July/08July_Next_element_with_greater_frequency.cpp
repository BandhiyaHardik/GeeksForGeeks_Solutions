class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};