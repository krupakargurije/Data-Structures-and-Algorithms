class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
        long long ans = 0;
        long long len = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (i > 0 && arr[i] == arr[i - 1] - 1) {
                len++;
            } else {
                len = 1;
            }
            ans += len;
        }
        return ans;
    }
};
