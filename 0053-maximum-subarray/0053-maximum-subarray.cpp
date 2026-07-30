class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int curr = 0;

        for(int i : nums){
            if(curr < 0)
                curr = 0;
            curr += i;
            ans = max(ans , curr);
        }
        return ans;
    }
};