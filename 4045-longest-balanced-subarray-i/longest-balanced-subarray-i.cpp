class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            unordered_map<int,int>mp;
            int even = 0,odd = 0;
            int temp = 0;

            for(int j = i;j<n;j++){
                if(mp[nums[j]] == 0) {
                    
                    if(nums[j] % 2 == 0)
                        even++;
                    else
                        odd++;
                }

                mp[nums[j]]++;

                if(even == odd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};