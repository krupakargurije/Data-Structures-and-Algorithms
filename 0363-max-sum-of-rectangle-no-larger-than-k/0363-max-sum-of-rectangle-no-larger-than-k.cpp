class Solution {
private:
    int helper(vector<int>& nums, int k) {
        set<int> st;
        st.insert(0);

        int prefix = 0;
        int ans = INT_MIN;

        for (int x : nums){
            prefix += x;
            auto it = st.lower_bound(prefix - k);

            if (it != st.end())
                ans = max(ans, prefix - *it);

            st.insert(prefix);
        }
        return ans;
    }

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Column-wise prefix sums
        vector<vector<int>> prefix(n, vector<int>(m));

        for (int j = 0; j < m; j++)
            prefix[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                prefix[i][j] = prefix[i - 1][j] + matrix[i][j];

        int ans = INT_MIN;
        for(int top = 0;top<n;top++){
            for(int bottum = top;bottum < n;bottum++){
                vector<int>arr(m);

                for(int col = 0;col<m;col++){
                    if(top == 0)
                        arr[col] = prefix[bottum][col];
                    else
                        arr[col] = prefix[bottum][col] - prefix[top - 1][col];
                }

                ans = max(ans , helper(arr , k));
                if(ans == k)return ans;
            }
        }
        return ans;
    }
};