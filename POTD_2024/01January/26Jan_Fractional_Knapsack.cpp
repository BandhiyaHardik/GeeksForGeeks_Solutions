class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, int>> items;
        
        for(int i = 0; i < n; i++){
            double value_per_weight = (double)arr[i].value / (double)arr[i].weight;
            
            items.emplace_back(value_per_weight, arr[i].weight);
        }
        
        sort(items.begin(), items.end(), [](pair<double, int> &a, pair<double, int> &b){
            return a.first > b.first; 
        });
        
        double ans = 0;
        
        for(int i = 0; i < n; i++){
            int take_weight = min(W, items[i].second);
            W -= take_weight;
            ans += take_weight * items[i].first;
        }
        
        return ans;
    }
        
};