class Solution{
public:
	
	int kSubstrConcat(int n, string s, int k) {
        if (n % k != 0) return 0;
    
        unordered_map<string, int> hm;
    
        for (int i = 0; i < n; i += k) {
            string sub = s.substr(i, k);
            hm[sub] = hm[sub] + 1;
        }
    
        int x = hm.size();
        if (x == 1) return 1;
        if (x == 2) for (auto val : hm) if (val.second == 1) return 1;
        return 0;
    }
};