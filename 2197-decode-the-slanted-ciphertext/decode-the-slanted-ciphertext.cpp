class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.length();

        string ans = "";
        int cols = n / rows;

        for (int j = 0; j < cols; j++) {
            int i = 0, col = j;

            while (i < rows && col < cols) {
                ans += s[i * cols + col];
                i++;
                col++;
            }
        }
        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};