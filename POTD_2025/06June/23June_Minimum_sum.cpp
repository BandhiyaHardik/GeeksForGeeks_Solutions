class Solution {
public:
    string addString(string& s1, string& s2) {
        int    i      = s1.length() - 1;
        int    j      = s2.length() - 1;
        int    c      = 0;
        string result = "";

        while (i >= 0 || j >= 0 || c > 0) {
            int sum = c;

            if (i >= 0) {
                sum += (s1[i] - '0');
            }
            if (j >= 0) {
                sum += (s2[j] - '0');
            }

            result.push_back(sum % 10 + '0');
            c = sum / 10;
            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string minSum(vector<int>& arr) {
        vector<int> count(10, 0);

        for (int num : arr) {
            count[num]++;
        }

        string s1   = "";
        string s2   = "";
        bool   flag = true;

        for (int digit = 0; digit < 10; digit++) {
            while (count[digit]--) {
                if (flag) {
                    if (!(s1.empty() && digit == 0)) {
                        s1.push_back(digit + '0');
                    }
                    flag = false;
                } else {
                    if (!(s2.empty() && digit == 0)) {
                        s2.push_back(digit + '0');
                    }
                    flag = true;
                }
            }
        }

        return addString(s1, s2);
    }
};