using ll = long long;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        ll  currGas= 0,total = 0;
        int start = 0;

        for(int i = 0;i<n;i++){
            ll diff = gas[i] - cost[i];
            currGas += diff;
            total += diff;

            if(currGas < 0){
                start = i + 1;
                currGas = 0;
            }
        }

        return total < 0 ? -1 : start;
    }
};