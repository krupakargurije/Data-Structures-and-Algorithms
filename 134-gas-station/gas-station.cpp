class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int ans = 0;
        int total = 0;


        for(int i = 0;i<n;i++){
            int diff = gas[i] - cost[i];

            total += diff;
            tank += diff;

            if(tank < 0){
                tank = 0;
                ans = i + 1;
            }
        }
        return total >= 0 ? ans : -1;
    }
};