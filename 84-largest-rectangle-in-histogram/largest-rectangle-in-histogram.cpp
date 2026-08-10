class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>leftMax(n , -1) , rightMax(n , n);

        for(int i = 0;i<n;i++){

            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();

            leftMax[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i = n - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();

            rightMax[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            int width = rightMax[i] - leftMax[i] - 1;
            ans = max(ans,nums[i] * width);
        }
        return ans;
    }
};








