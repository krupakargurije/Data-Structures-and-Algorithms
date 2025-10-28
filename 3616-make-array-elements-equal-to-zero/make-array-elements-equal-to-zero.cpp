class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,0),suff(n,0);

        for(int i = 1;i<n;i++){
            pref[i] = pref[i - 1] + nums[i - 1];
            suff[n - i - 1] = suff[n - i] + nums[n - i];
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] != 0)continue;

            if(pref[i] == suff[i])ans += 2;
            else if(abs(pref[i] - suff[i]) == 1) ans++;
        }
        return ans;
    }
};