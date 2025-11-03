class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int n = colors.size();
        int ans = 0;
        int prev = 0;

        for(int i = 1;i<n;i++){
            if(colors[i] == colors[prev]){
                if(arr[prev] >= arr[i]){
                    ans += arr[i];
                    continue;
                }
                else{
                    ans += arr[prev];
                    prev = i;
                }
            }
            else{
                prev = i;
            }
        }
        return ans;
    }
};