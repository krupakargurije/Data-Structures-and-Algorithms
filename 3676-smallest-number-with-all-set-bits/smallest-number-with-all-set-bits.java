class Solution {
    public int smallestNumber(int n) {
        if(n == 1)return 1;
        int ans = 3;
        while(ans >= 0){
            if(ans >= n)return ans;
            ans = (2 * ans) + 1;
        }
        return 0;
    }
}