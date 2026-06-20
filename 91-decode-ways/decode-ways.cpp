class Solution {
    vector<int>dp;
private:
    int helper(string &s, int idx) {
        if (idx == s.size())
            return 1;

        if (s[idx] == '0')
            return 0;

        if(dp[idx] != -1)return dp[idx];

        int picOne = helper(s, idx + 1);

        int picTwo = 0;
        if (idx + 1 < s.size()) {
            int num = stoi(s.substr(idx, 2));

            if (num >= 10 && num <= 26)
                picTwo = helper(s, idx + 2);
        }
        return dp[idx] = picOne + picTwo;
    }

public:
    int numDecodings(string s) {
        dp.resize(s.length() , -1);
        return helper(s, 0);
    }
};