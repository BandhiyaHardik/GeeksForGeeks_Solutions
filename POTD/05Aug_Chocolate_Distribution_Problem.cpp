class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
        long ans = LONG_MAX;
        for (int i = 0; i < n - m + 1; i++) {
            int j = i + m - 1;
            if (a[j] - a[i] < ans)
                ans = a[j] - a[i];
        }
        return ans;
    }   
};