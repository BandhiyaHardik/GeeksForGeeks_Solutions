class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	     int *low = lower_bound(arr, arr + n, x);
	    if (*low != x)
	        return 0;
	    int *high = upper_bound(low, arr + n, x);
	    return high - low;
	}
};