class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> countDiffMap;
        int countDiff = 0;
        int result = 0;

        countDiffMap[0] = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                countDiff++;
            }
            if (arr[i] == y) {
                countDiff--;
            }

            result += countDiffMap[countDiff];

            countDiffMap[countDiff]++;
        }

        return result;
    }
};
