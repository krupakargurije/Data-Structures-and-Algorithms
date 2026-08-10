class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>leftSmaller(n , -1) , rightSmaller(n , n);

        for(int i = 0;i<n;i++){

            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();

            leftSmaller[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i = n - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();

            rightSmaller[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            int width = rightSmaller[i] - leftSmaller[i] - 1;
            ans = max(ans,nums[i] * width);
        }
        return ans;
    }
};








