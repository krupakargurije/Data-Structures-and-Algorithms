class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n){
            ans = max(ans , c - '0');
            if(ans == 9)return 9;
        }
        return ans;
    }
};