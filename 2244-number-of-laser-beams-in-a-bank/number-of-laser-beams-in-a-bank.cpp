class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevSum = 0;
        
        for (auto& row : bank) {
            int currSum = 0;
            for (char c : row) {
                if (c == '1') currSum++;
            }

            if (currSum > 0) {
                ans += currSum * prevSum;
                prevSum = currSum;
            }
        }
        return ans;
    }
};
