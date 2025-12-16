class Solution {
private:
    bool helper(vector<int>& arr, int idx, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (idx == 0) return arr[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = helper(arr, idx - 1, target, dp);
        bool take = false;

        if (arr[idx] <= target) {
            take = helper(arr, idx - 1, target - arr[idx], dp);
        }

        return dp[idx][target] = take || notTake;
    }

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(arr, n - 1, sum, dp);
    }
};
