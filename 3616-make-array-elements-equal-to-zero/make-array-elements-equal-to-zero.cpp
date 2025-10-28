class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int right = 0,left = 0;

        for(int i : nums){
            right += i;
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            left += nums[i];
            right -= nums[i];
            if(nums[i] != 0)continue;

            if(left == right) ans += 2;
            else if(abs(left - right) == 1)ans++;
        }
        return ans;
    }
};