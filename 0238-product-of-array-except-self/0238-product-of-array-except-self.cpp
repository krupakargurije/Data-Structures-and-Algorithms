class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>suff(n);
        suff[n-1] = nums[n-1];

        for(int i = n - 2;i>= 0;i--){
            suff[i] = suff[i + 1] * nums[i];
        }

        vector<int>ans(n);
        int pref = nums[0];
        ans[0] = suff[1];

        for(int i = 1;i<n - 1;i++){
            ans[i] = pref * suff[i + 1];
            pref *= nums[i];
        }

        ans[n-1] = pref;
        return ans;
    }
};