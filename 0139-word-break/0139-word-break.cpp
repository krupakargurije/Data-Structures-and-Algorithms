class Solution {
private:
    bool helper(string &s, int idx, unordered_set<string> &st, vector<int> &dp) {
        if (idx == s.length())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string curr = "";

        for (int i = idx; i < s.length();i++) {
            curr += s[i];

            if (st.find(curr) != st.end()) {

                if (helper(s, i + 1, st, dp))
                    return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto &word : wordDict)
            st.insert(word);

        vector<int> dp(s.length(), -1);
        return helper(s, 0, st, dp);
    }
};