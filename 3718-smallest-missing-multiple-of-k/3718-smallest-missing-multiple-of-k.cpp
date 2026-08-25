class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>st(101 , 0);

        for(int it : nums){
            st[it] = 1;
        }

        for(int i = k; i < st.size();i += k){
            if(!st[i])return i;
        }
        return ((100 / k) + 1) * k;
    }
};