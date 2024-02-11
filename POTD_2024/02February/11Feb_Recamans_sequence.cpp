class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> ans = {0};
        unordered_set<int> included;
        
        for(int i = 1; i < n; i++){
            int add, sub;
            add = ans.back() + i;
            sub = ans.back() - i;
            
            if(sub > 0 and (included.find(sub) == included.end())){
                ans.push_back(sub);
                included.insert(sub);
            }
            else{
                ans.push_back(add);
                included.insert(add);
            }
        }
        
        return ans;
    }
};