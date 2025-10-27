class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevSum = 0;
        
        for(auto it : bank){
            int currSum = 0;
            for(int i : it){
                if(i == '1')currSum++;
            }
            if(currSum > 0){
                ans += currSum * prevSum;
                prevSum = currSum;
            }
        }
        return ans;
    }
};