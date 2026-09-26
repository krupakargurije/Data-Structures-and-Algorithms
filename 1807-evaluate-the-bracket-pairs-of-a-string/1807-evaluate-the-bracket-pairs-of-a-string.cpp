class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto& it : knowledge) {
            mp[it[0]] = it[1];
        }

        string ans = "";
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                string key = "";
                int last = i + 1;

                while (last < s.length() && s[last] != ')') {
                    key += s[last];
                    last++;
                }

                if (mp.find(key) == mp.end()) {
                    ans += '?';
                } else {
                    ans += mp[key];
                }

                // last is the index of ')'
                i = last;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};