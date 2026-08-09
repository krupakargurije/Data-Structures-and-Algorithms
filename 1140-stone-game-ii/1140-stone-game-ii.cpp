class Solution {
    private:
    int dp[2][101][101];
    int helper(vector<int> &nums , int person , int i , int m){
        int n = nums.size();
        if(i >= n)
            return 0;

        if(dp[person][i][m] != -1)
            return dp[person][i][m];
        
        int result = (person == 0) ? -1 : INT_MAX;
        int total = 0;

        for(int x = 1;x <= min(2 * m , n - i);x++){
            total += nums[i + x -1];
            if(!person){
                result = max(result , total + helper(nums , 1 , i + x , max(m , x)));
            }
            else{
                result = min(result , helper(nums , 0 , i + x , max(m , x)));
            }
        }
        return dp[person][i][m] = result;
    }
public:
    int stoneGameII(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return helper(nums , 0 , 0 , 1);
    }
};

// 2,7,9,4,4,2,7,9,4,4   1 , 2 , 
// a-> 2 b -> 7 , 9
// a -> 4 , 4 = 2 + 4 + 4 = 10