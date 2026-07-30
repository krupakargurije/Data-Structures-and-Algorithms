class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int pref = nums[0];
        ans[0] = 1;

        for(int i = 1;i<n;i++){
            ans[i] = pref;
            pref *= nums[i];
        }

        int suff = nums[n - 1];
        for(int i = n - 2;i>=0;i--){
            ans[i] *= suff;
            suff *= nums[i];
        }
        return ans;
    }
};

// 1,2,3,4
// 24,12,8,6

// 