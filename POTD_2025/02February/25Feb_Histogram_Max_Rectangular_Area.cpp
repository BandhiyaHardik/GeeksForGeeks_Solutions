class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> s;
        int maxArea = 0;
        int i = 0;

        while (i < n) {
            if (s.empty() || arr[s.top()] <= arr[i]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, arr[top] * width);
            }
        }
        
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, arr[top] * width);
        }
        
        return maxArea;
    }
};
