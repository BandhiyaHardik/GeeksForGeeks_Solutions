class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	   int msis[n];
        msis[0] = arr[0];
        int res = msis[0];
    
        for (int i = 1; i < n; i++) {
            msis[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                    msis[i] = msis[j] + arr[i];
                }
            }
            res = max(res, msis[i]);
        }
        return res;
	}  
};