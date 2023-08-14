class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
       int n = arr.size();
        int all = 0;
        for (int i = 0; i < n; i++)
            all = all ^ arr[i];

        int m = all & -all;

        int g1 = 0, g2 = 0;
        for (int i = 0; i < n; i++) {
            if ((m & arr[i]) == 0) {
                g1 ^= arr[i];
            } else {
                g2 ^= arr[i];
            }
        }

        std::vector<int> ans;
        if (g1 > g2) {
            ans.push_back(g2);
            ans.push_back(g1);
        } else {
            ans.push_back(g1);
            ans.push_back(g2);
        }

        return ans;
    }
};