class Solution{
  public:
    int longestKSubstr(string s, int k) {
    unordered_map<char, int> m;
        int uniq_ch = 0, i = 0, j = 0, ans = 0, n = s.length();

        while (j < n) {
          
            while (j < n) {
                char ch = s[j];
                if (m.find(ch) == m.end() || m[ch] == 0) uniq_ch++;
                m[ch] = m[ch] + 1;
             
                if (uniq_ch > k) break;
                j++;
            }

            if (uniq_ch >= k) ans = max(ans, j - i);
            
            if (j == n) break;

            while (i < n) {
                char ch = s[i];
                if (m[ch] == 1) uniq_ch--;
                m[ch] = m[ch] - 1;

                if (uniq_ch == k) break;
                i++;
            }
            i++;
            j++;
        }
        if (ans == 0) return -1;
        return ans;
    }
};