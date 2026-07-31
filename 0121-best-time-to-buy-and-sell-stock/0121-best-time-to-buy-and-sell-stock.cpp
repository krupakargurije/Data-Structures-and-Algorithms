class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)return 0;

        int ans = INT_MIN;
        int leftMin = nums[0];

        for(int i = 1 ; i < n ;i++){
            leftMin = min(leftMin , nums[i]);
            ans = max(ans , nums[i] - leftMin);
        }
        return ans;
    }
};

// 7,1,5,3,6,4  j - i = diff n - 2 tc -> n * n == O(n ^ 2)  sc -> O(1)
// ans = max(ans , diff)

// minLeft = min(minLeft , nums[i])
// 7,1,5,3,6,4  min = 1 ans = 5
// 3