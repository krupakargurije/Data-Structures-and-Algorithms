class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        // Iterate over all possible subarrays of length k
        for (int i = 0; i + k <= n; i++) {
            vector<int> sub(nums.begin() + i, nums.begin() + i + k);

            // Count frequencies
            unordered_map<int, int> freq;
            for (int num : sub) {
                freq[num]++;
            }

            // Store (num, freq) pairs
            vector<pair<int, int>> items(freq.begin(), freq.end());

            // Sort by frequency DESC, then by value DESC
            sort(items.begin(), items.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            // Choose top-x elements
            unordered_set<int> top_x;
            for (int j = 0; j < (int)items.size() && j < x; j++) {
                top_x.insert(items[j].first);
            }

            // Compute x-sum of this subarray
            int x_sum = 0;
            for (int num : sub) {
                if (top_x.count(num)) x_sum += num;
            }

            ans.push_back(x_sum);
        }

        return ans;
    }
};
