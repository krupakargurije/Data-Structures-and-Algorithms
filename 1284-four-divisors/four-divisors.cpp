class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int  x : nums){
            int currSum = 0,count = 0;

            for(int div = 1;div * div <= x;div++){
                if(count > 4)break;
                if (x % div == 0) {
                    int other = x / div;

                    if (div == other) {
                        currSum += div;
                        count += 1;
                    } else {
                        currSum += div + other;
                        count += 2;
                    }
                }
            }
            if(count == 4)ans += currSum;
        }
        return ans;
    }
};