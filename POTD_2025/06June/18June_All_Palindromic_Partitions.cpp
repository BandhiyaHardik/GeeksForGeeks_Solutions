class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int idx,
                   string& s,
                   vector<string>& curr,
                   vector<vector<string> >& result) {
        if (idx == s.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {

            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));

                backtrack(i + 1, s, curr, result);

                curr.pop_back();
            }
        }
    }

    vector<vector<string> > palinParts(string& s) {
        vector<vector<string> > result;
        vector<string>          curr;

        backtrack(0, s, curr, result);
        return result;
    }
};