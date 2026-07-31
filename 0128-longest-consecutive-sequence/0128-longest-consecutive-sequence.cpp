class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;
        for (int i : st){
            int curr = 0;

            if (!st.count(i - 1)){
                int temp = i;

                while (st.count(temp)) {
                    curr++;
                    temp++;
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};