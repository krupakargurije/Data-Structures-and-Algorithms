using ll = long long;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nextMx(n, n), nextMn(n, n);
        vector<int> prevMx(n, -1), prevMn(n, -1);

        stack<int> st;

        // Previous Greatest Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            prevMx[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Minimum Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            prevMn[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greatest Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            nextMx[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Minimum Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            nextMn[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            ll maxCnt = 1LL * (i - prevMx[i]) * (nextMx[i] - i);
            ll minCnt = 1LL * (i - prevMn[i]) * (nextMn[i] - i);

            ans += 1LL * nums[i] * (maxCnt - minCnt);
        }
        return ans;
    }
};