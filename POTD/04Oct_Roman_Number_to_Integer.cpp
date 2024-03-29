class Solution {
  public:
    int romanToDecimal(string &str) {
       unordered_map<char, int> romanMap;
        int n = str.length();
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (romanMap[str[i]] < romanMap[str[i + 1]]) {
                sum -= romanMap[str[i]];
            } else {
                sum += romanMap[str[i]];
            }
        }
        sum += romanMap[str[n - 1]];
        return sum;
    }
};