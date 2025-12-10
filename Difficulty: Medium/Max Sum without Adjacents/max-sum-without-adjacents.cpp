// User function template for C++
class Solution {
private:
    long long helper(vector<int>& arr, vector<long long>& dp, int idx){
        
        if(idx == 0)   return arr[0];
        if(idx < 0)    return 0;

        if(dp[idx] != -1) 
            return dp[idx];

        long long pick = arr[idx] + helper(arr, dp, idx - 2);
        long long nonPick = helper(arr, dp, idx - 1);

        return dp[idx] = max(pick, nonPick);
    }

public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<long long> dp(n, -1);  // <-- FIXED

        return (int)helper(arr, dp, n - 1);
    }
};
