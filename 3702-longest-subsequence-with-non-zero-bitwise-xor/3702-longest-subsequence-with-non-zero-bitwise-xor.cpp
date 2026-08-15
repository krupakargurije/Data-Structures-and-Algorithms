class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i : nums){
            sum ^= i;
        }

        if(sum != 0)return n;
        for(int i : nums){
            if(i != 0)return n - 1;
        }
        return 0;
    }
};