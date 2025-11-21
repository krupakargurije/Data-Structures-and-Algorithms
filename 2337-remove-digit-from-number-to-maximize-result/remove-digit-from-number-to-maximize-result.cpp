class Solution {
public:
    string removeDigit(string num, char dig) {
        string ans = "";
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            if (num[i] == dig) {
                string temp = num.substr(0, i) + num.substr(i + 1);
                if (temp > ans) ans = temp;
            }
        }
        return ans;
    }
};
