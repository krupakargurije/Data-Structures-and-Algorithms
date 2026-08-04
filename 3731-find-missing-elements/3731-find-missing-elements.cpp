class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>st;
        int start = INT_MAX , end = INT_MIN;
        int n = nums.size();

        vector<int>ans;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
            start = min(start , nums[i]);
            end = max(end , nums[i]);
        }

        for(int i = start;i<=end;i++){
            if(!st.count(i))ans.push_back(i);
        }
        return ans;
    }
};