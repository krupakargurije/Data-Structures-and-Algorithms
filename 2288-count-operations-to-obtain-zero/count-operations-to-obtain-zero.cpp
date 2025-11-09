class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0)return 0;
        int ans = 0;
        while(num1|| num2){
            if(num1 == num2){
                return ans += 1;
            }
            else if(num1 > num2){
                num1 -= num2;
                ans++;
            }
            else{
                num2 -= num1;
                ans++;
            }
        }
        return ans;
    }
};