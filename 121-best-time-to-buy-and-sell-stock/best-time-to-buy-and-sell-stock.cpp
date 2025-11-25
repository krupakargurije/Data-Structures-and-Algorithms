class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0,minPrice = prices[0];
        for(int i : prices){
            minPrice = min(minPrice,i);
            maxProfit = max(maxProfit,i-minPrice);
        }
        return maxProfit;
    }
};