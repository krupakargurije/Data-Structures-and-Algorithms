class Solution {
public:
    int findFinalValue(vector<int>& nums, int ans) {
        unordered_set<int> st;
        for(int i : nums)st.insert(i);

        while(st.find(ans) != st.end())ans *= 2;
        return ans;
    }
};