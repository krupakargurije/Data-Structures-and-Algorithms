class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        // Count frequency of each digit
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        // Try every 3-digit even number
        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int a = x / 100;        // hundreds
            int b = (x / 10) % 10;  // tens
            int c = x % 10;         // units

            // Need a, b, c from the available digits
            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};