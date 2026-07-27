class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int x1 = 0 , x2 = 0;

        for(int i : nums){
            if(i > x1){
                x2 = x1;
                x1 = i;
            }
            else if(i > x2)
                x2 = i;
        }
        return (x1 - 1) * (x2 - 1);
    }
};