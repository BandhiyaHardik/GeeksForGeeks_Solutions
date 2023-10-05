class Solution
{
  public:
    long long int substrCount (string s, int k) {
     return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }

    long atMostKDistinct(std::string s, int k) {
        if (k < 0) return 0;
        
        int i = 0, j = 0, cnt = 0;
        long ans = 0;
        int charCount[26] = {0};

        while (j < s.length()) {
            char currentChar = s[j] - 'a';
            charCount[currentChar]++;

            if (charCount[currentChar] == 1) cnt++;

            while (cnt > k) {
                char removedChar = s[i] - 'a';
                charCount[removedChar]--;
                if (charCount[removedChar] == 0) {
                    cnt--;
                }

                i++;
            }

            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};