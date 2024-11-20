class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        if (n == 0) return ans;

        int ele1 = 0, ele2 = 0, count1 = 0, count2 = 0;

        for (int num : arr) {
            if (num == ele1) {
                count1++;
            } else if (num == ele2) {
                count2++;
            } else if (count1 == 0) {
                ele1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                ele2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int num : arr) {
            if (num == ele1) count1++;
            else if (num == ele2) count2++;
        }

        if (count1 > n / 3) ans.push_back(ele1);
        if (count2 > n / 3) ans.push_back(ele2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
