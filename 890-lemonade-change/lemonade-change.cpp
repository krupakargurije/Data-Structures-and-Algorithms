class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int five = 0, ten = 0;
        
        for (int bill : nums) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
