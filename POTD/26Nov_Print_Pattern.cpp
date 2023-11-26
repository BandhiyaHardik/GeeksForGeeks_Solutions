class Solution{
public:
    void helper(int cur, int N, vector<int> &ans, int dx){
        ans.push_back(cur);
            
        if(cur <= 0)
            dx = 5;
        
        if(cur < N or dx == -5)    
            helper(cur + dx, N, ans, dx);
    }
    
    vector<int> pattern(int N){
        vector<int> ans;
        helper(N, N, ans, -5);
        
        return ans;
    }
};