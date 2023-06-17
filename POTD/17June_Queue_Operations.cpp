// Helper class Solution to implement 
// insert() and findFrequency()
class Solution{
    public:
    // Function to insert element into the queue
    void insert(queue<int> &q, int k){
        // Your code here
        q.push(k);
    }
    
    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k){
        // Your code here
         queue<int> c_q;
        int ans = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            c_q.push(curr);
            if (curr == k)
                ans++;
        }
        while (!c_q.empty()) {
            q.push(c_q.front());
            c_q.pop();
        }
        return ans;
    }
    
};

