class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pref = 1 , suff = 1;
        int i = 0;

        while(i < n){
            pref *= nums[i];
            suff *= nums[n - i - 1]; // 1 2 4 7 9

            ans = max(ans , pref);
            ans = max(ans , suff);

            if(nums[i] == 0)
                pref = 1;
            if(nums[n - i - 1] == 0)
                suff = 1;
            i++;
        }
        return ans;
    }
};