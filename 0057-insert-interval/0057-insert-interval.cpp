class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;
        bool inserted = false;

        for (auto &curr : intervals) {

            // Insert newInterval before curr if needed
            if (!inserted && newInterval[0] < curr[0]) {

                if (ans.empty() || ans.back()[1] < newInterval[0])
                    ans.push_back(newInterval);
                else
                    ans.back()[1] = max(ans.back()[1], newInterval[1]);

                inserted = true;
            }

            // Process current interval
            if (ans.empty() || ans.back()[1] < curr[0])
                ans.push_back(curr);
            else
                ans.back()[1] = max(ans.back()[1], curr[1]);
        }

        // If newInterval is the largest interval
        if (!inserted) {
            if (ans.empty() || ans.back()[1] < newInterval[0])
                ans.push_back(newInterval);
            else
                ans.back()[1] = max(ans.back()[1], newInterval[1]);
        }

        return ans;
    }
};