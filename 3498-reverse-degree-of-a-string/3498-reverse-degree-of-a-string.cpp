class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int idx = 1;
        for(char c : s){
            int revDegree = 26 - (c - 'a');
            ans += (idx * revDegree);
            idx++;
        }
        return ans;
    }
};