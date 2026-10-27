class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m , string(n - 1 , '#') + '.');

        ans[0] = string(n , '.');
        return ans;
    }
};