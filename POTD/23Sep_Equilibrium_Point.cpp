class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        if(n==1)
        return 1;
        
        long long sum = 0 ;
        for( int i = 0 ; i<n ;i++)
        {
            sum+=arr[i];
        }
        
        long long lsum=0;
        for( int i = 0; i<n ;i++)
     {
         if(lsum == sum-arr[i])
         return i+1;
         
         lsum +=arr[i];
         sum -= arr[i];
     }
     return -1;
    }

};