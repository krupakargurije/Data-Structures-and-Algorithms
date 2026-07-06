class Solution {
public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int ans = 0;

        while (i < n && j < m) {
            if (a[i] < b[j]) {
                sum1 += a[i];
                i++;
            }
            else if (a[i] > b[j]) {
                sum2 += b[j];
                j++;
            }
            else {
                // Common element found
                ans += max(sum1, sum2) + a[i];

                sum1 = 0;
                sum2 = 0;

                i++;
                j++;
            }
        }

        while (i < n) {
            sum1 += a[i];
            i++;
        }

        while (j < m) {
            sum2 += b[j];
            j++;
        }

        ans += max(sum1, sum2);

        return ans;
    }
};