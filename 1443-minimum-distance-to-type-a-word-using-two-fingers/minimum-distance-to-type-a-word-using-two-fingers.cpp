class Solution {
    private:
    int dp[301][27][27];
    int getDist(int a , int b){
        if(a == -1 || b == -1)return 0;

        int r1 = a / 6 , r2 = b / 6;
        int c1 = a % 6 , c2 = b% 6;

        return abs(r1 - r2) + abs(c1 - c2);
    }

    int helper(string word , int idx , int f1 , int f2){
        if(idx < 0)return 0;
        int curr = word[idx] - 'A';

        if(dp[idx][f1+1][f2+1] != -1)
            return dp[idx][f1+1][f2+1];

        int usef1 = getDist(f1 , curr) + helper(word , idx - 1 , curr , f2);
        int usef2 = getDist(f2 , curr) + helper(word , idx - 1 , f1 , curr);

        return dp[idx][f1 + 1][f2 + 1] = min(usef1 , usef2);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        memset(dp , -1 , sizeof(dp));
        return helper(word , n-1 , -1 , -1);
    }
};