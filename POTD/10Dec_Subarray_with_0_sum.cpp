class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> found;
        found[0] = 1;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(found.count(sum))
                return 1;
                
            ++found[sum];
        }
        
        return 0;
    }
};