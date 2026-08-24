class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; // stores indices
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--){
            int idx = i % n;

            while (!st.empty() && nums[idx] >= nums[st.top()]) {
                st.pop();
            }

            if (i < n && !st.empty()) {
                ans[idx] = nums[st.top()];
            }

            st.push(idx);
        }
        return ans;
    }
};