
bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
    vector<int> ways(target+1, 0);
    for (int i = 0; i < N; i++) {
        if (coins[i] <= target) {
            ways[coins[i]] = 1;
        }
    }
    for (int i = 1; i < K; i++) {
        vector<int> newWays(target+1, 0);
         for (int j = 0; j <= target; j++) {
            if (ways[j] == 1) {
                for (int k = 0; k < N; k++) {
                    if ((j+coins[k]) <= target) {
                        newWays[j+coins[k]] = 1;
                    }
                }
            }
        }
        ways = newWays;
    }
    return ways[target] == 1;
    }
