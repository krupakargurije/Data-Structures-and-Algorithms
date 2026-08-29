class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        // Store {value, original index}
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort according to value
        sort(arr.begin(), arr.end());

        vector<int> result(n);

        int start = 0;
        while (start < n) {
            int end = start;

            // Find one complete swappable group
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Collect original indices
            vector<int> indices;
            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            // Values are already sorted because arr is sorted
            sort(indices.begin(), indices.end());

            // Put smallest values at smallest indices
            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = arr[start + i].first;
            }

            start = end + 1;
        }
        return result;
    }
};