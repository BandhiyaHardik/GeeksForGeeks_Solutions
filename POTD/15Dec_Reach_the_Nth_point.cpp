class Solution{
	public:
		int nthPoint(int n){
		    long long a, b;
		    a = b = 1;
		    
		    const long long mod = 1e9 + 7;
		    
		    for(int i = 1; i < n; i++){
		        long long c = (a + b) % mod;
		        a = b;
		        b = c;
		    }
		    
		    return b;
		}
};