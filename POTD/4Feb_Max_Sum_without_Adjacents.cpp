class Solution{
public:	
	// calculate the maximum sum with out adjacent

	int findMaxSum(int *arr, int n) {
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    for (int i = 1; i < n; i++) {
        if (incl > excl) {
            excl_new = incl;
        } else {
            excl_new = excl;
        }
        incl = excl + arr[i];
        excl = excl_new;
    }
    if (incl > excl) {
        return incl;
    } else {
        return excl;
    }
}
	
};