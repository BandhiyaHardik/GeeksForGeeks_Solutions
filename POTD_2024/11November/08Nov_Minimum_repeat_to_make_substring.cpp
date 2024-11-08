class Solution {
  public:
    int minRepeats(string& s1, string& s2) {

        int repeatCount = 1;
        string repeatedS1 = s1;
        
        while (repeatedS1.length() < s2.length()) {
            repeatedS1 += s1;
            repeatCount++;
        }
        
        if (repeatedS1.find(s2) != string::npos) {
            return repeatCount;
        }
        
        repeatedS1 += s1;
        repeatCount++;

        if (repeatedS1.find(s2) != string::npos) {
            return repeatCount;
        }
        
        return -1;
    }
};
