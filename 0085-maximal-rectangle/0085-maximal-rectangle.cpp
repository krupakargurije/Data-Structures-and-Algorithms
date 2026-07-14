class Solution {
    private:
    int helper(vector<int>& nums){
        int n = nums.size();
        
        stack<int> st;
        vector<int>prev(n , -1) , next(n , -1);

        // Next Smaller
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            next[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous Smaller
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            prev[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            int w = next[i] - prev[i] - 1;
            ans = max(ans , nums[i] * w);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>nums(n , vector<int> (m , 0));

        for(int j = 0;j<m;j++){
            nums[0][j] = matrix[0][j] - '0';
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                    nums[i][j] = nums[i-1][j]+1;
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans , helper(nums[i]));
        }
        return ans;
    }
};