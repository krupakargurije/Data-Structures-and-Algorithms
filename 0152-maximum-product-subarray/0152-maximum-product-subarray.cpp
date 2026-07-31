class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pref = 1;

        for(int i = 0;i<n;i++){
            pref *= nums[i];
            ans = max(ans , pref);
            if(nums[i] == 0)
                pref = 1;
        }

        int suff = 1;
        for(int j = n-1;j>=0;j--){
            suff *= nums[j];
            ans = max(ans , suff);
            if(nums[j] == 0)
                suff = 1;
        }
        return ans;
    }
};