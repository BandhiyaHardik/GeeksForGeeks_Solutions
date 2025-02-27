class Solution {
  public:
    int mini;
    stack<int>st;
    Solution() {

    }
    // Add an element to the top of Stack
    void push(int x) {
        if(st.empty()) mini=x;
        else if(x<=mini){
            st.push(mini);
            mini=x;
        }
        st.push(x);
    }
    // Remove the top element from the Stack
    void pop() {
        if(st.empty()) return;
        int temp=st.top();
        st.pop();
        if(temp==mini && !st.empty() ){
            mini=st.top();
            st.pop();
        }
    }
    // Returns top element of the Stack
    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }
    // Finds minimum element of Stack
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};