class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;

        int curr = 0;
        for(int i : nums){
            curr += i;
            ans.push_back(curr);
        }
        return ans;
    }
};