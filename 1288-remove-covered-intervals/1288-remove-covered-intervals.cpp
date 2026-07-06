class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];   // Descending end if same start
            return a[0] < b[0];
        });
        stack<pair<int , int>>st;
        st.push({nums[0][0] , nums[0][1]});

        for(int i = 1;i < n;i++){
            auto [c , d] = st.top();
            int a = nums[i][0];
            int b = nums[i][1];

            if(c <= a && b <= d)
                continue;
            else
                st.push({a , b});
        }
        return st.size();
    }
};