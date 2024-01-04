class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        vector<int> f(32, 0);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 32; j++){
                f[j] += (arr[i] >> j) & 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++)
            ans += (f[i] % 3) << i;
            
        return ans;
    }
};