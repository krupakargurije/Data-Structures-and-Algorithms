class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {{}};

        unordered_map<string, vector<string>> mp;

        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // Sorted string acts as the key
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second); // push back the same kesy having the same strings as values
        }

        return ans;
    }
};
