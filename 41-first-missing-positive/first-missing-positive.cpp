class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        for(int i = 1;i<=nums.size();i++){
            if(st.find(i) ==st.end())return i;
        }
        return nums.size()+1;
    }
};