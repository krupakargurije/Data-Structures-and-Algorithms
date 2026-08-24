class Solution {
    private:
    vector<int>prefix;
    vector<int>dp;
    int len;

    int helper(int idx){
        if(idx == len - 1)
            return prefix[len-1];
        
        if(dp[idx] != INT_MIN)
            return dp[idx];
        
        int pic = prefix[idx] - helper(idx + 1);
        int skip = helper(idx + 1);

        return dp[idx] = max(pic , skip);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        len = n;

        prefix.resize(n);
        dp.assign(n , INT_MIN);

        prefix[0] = stones[0];

        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i - 1] + stones[i];
        }
        int ans = helper(1);
        return ans;
    }
};