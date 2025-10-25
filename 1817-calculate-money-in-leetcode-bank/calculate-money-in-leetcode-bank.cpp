class Solution {
public:
    int totalMoney(int n) {
        int j = 1,count = 1;
        int ans = 0;
        while(count <= n){
            for(int i = j;i < j + 7 && count <= n;i++) {
                ans += i;
                count++;
            }
            j++;
        }
        return ans;
    }
};