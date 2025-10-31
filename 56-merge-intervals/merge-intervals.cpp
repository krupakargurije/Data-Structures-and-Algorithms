class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            auto& last = ans.back();
            auto& curr = intervals[i];

            if (curr[0] <= last[1]) {
                last[1] = max(last[1], curr[1]);
            } else {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
