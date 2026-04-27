class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;

        long long curr = 0;
        for(int i : nums){
            curr += (long long)i;
            ans.push_back((int)curr);
        }
        return ans;
    }
};