class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        int n = words.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int left = (start - i + n) % n;
                int right = (i - start + n) % n;
                ans = min(ans, min(left, right));
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};