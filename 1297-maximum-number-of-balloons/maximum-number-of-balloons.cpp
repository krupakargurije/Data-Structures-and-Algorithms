class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(char c : text) mp[c]++;

        string str = "balloon";
        unordered_map<char,int> countNeeded;
        for(char c : str) countNeeded[c]++;

        int ans = INT_MAX;
        for(auto &[c, cnt] : countNeeded) {
            ans = min(ans, mp[c] / cnt);
        }

        return ans;
    }
};
