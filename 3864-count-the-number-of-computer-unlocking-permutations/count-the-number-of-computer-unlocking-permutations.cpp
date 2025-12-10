class Solution {
public:
    int countPermutations(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int f = nums[0];
        int n = nums.size();
        int minEle = *min_element(nums.begin()+1,nums.end());

        if(f >= minEle)return 0;
        long long ans = 1;

        for(int i = 1;i <= n-1;i++){
            ans *= i;
            ans %= MOD;
        }
        return ans;
    }
};