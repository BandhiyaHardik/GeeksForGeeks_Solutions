class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> f;
        
        for(int i = 0; i < n; i++){
            ++f[arr[i]];
        }
        
        int ans = 0;
        
        for(auto i : f){
            ans += i.second > (n / k);
        }
        
        return ans;
    }
}; 