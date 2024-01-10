class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum = 0;
	    unordered_map<int,int> suffix;
	    suffix[0] = n;
	    
	    int ans = 0;
	    
	    for(int i = n - 1; i > -1; i--){
	        sum = (sum + (arr[i] % k) + k) % k;
	        
	        if(!suffix.count(sum))
	            suffix[sum] = i;
	        else
	            ans = max(ans, suffix[sum] - i);
	    }
	    
	    return ans;
	}
};
