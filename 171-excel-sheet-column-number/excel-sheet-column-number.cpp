class Solution {
public:
    int titleToNumber(string str) {
        int ans = 0;

        for (char c : str) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};
