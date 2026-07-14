class Solution {
    int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();

        vector<int> next(n), prev(n);
        stack<int> st;

        // next smaller Ele
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            next[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // prev smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            prev[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + 1LL * nums[i] * left * right) % MOD;
        }
        return ans;
    }
};