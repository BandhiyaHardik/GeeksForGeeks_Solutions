class Solution {
public:
    int minDist(int a[], int n, int x, int y) {
        int minDistance = INT_MAX;
        int lastXIndex = -1;
        int lastYIndex = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                if (lastYIndex != -1) {
                    minDistance = min(minDistance, i - lastYIndex);
                }
                lastXIndex = i;
            } else if (a[i] == y) {
                if (lastXIndex != -1) {
                    minDistance = min(minDistance, i - lastXIndex);
                }
                lastYIndex = i;
            }
        }

        if (minDistance == INT_MAX) {
            return -1; 
        }

        return minDistance;
    }
};