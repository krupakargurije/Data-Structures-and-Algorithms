class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n , 0);
        stack<int>st;

        for(int i = n - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] <= nums[i])st.pop();

            ans[i] = !st.empty() ? st.top() - i : 0;
            st.push(i);
        }
        return ans;
    }
};