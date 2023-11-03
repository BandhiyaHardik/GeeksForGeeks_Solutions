class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	     int max = 0;

        for (int i = 0; i < n; i++) {
            max = std::max(max, arr[i]);
        }
        max = max * max;

        std::vector<int> freq(max + 1, 0);

        for (int i = 0; i < n; i++) {
            freq[arr[i] * arr[i]]++;
        }

        for (int i = 1; i <= max; i++) {
            if (freq[i] == 0) {
                continue;
            }

            for (int j = 1; j <= max; j++) {
                if (freq[j] == 0 || (i == j && freq[i] == 1)) {
                    continue;
                }

                int c = i + j;
                if (c > max) {
                    continue;
                }
                if (freq[c] > 0) {
                    return true;
                }
            }
        }
        return false;
	}
};