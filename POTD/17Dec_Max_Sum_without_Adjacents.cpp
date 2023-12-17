class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int next_0, next_1;
	    next_0 = next_1 = 0;
	    
	    for(int i = n - 1; i > -1; i--){
	        int cur_0 = max(arr[i] + next_1, next_0);
	        int cur_1 = next_0;
	        
	        next_0 = cur_0;
	        next_1 = cur_1;
	    }
	    
	    return next_0;
	}
};