class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> info(n);
        
        for(int i = 0; i < n; i++){
            info[i].first = price[i];
            info[i].second = i + 1;
        }
        
        sort(info.begin(), info.end());
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int qty = k / info[i].first;
            qty = min(qty, info[i].second);
            
            ans += qty;
            k -= qty * info[i].first;
        }
        
        return ans;
    }
};