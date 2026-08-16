class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        // Count stones based on remainder
        for (int stone : stones) {
            cnt[stone % 3]++;
        }

        // Even number of remainder-0 stones
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // Odd number of remainder-0 stones
        return abs(cnt[1] - cnt[2]) > 2;
    }
};