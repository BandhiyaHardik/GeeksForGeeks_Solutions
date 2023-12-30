class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> votes;
        
        for(int i = 0; i < n; i++)
            ++votes[arr[i]];
            
        int best = 0;
        vector<string> ans(2);
        
        for(auto i : votes){
            if(i.second > best){
                best = i.second;
                ans[0] = i.first;
                ans[1] = to_string(best);
            }
            else if(i.second == best and i.first < ans[0]){
                ans[0] = i.first;
            }
        }
        
        return ans;
    }
};