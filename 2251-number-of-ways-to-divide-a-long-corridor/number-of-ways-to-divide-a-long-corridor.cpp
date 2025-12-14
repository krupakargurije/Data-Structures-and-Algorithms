class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int seats = 0;
        
        for (char c : corridor) {
            if (c == 'S') seats++;
        }

        if (seats == 0 || seats % 2 != 0) return 0;

        long long ways = 1;
        int countSeats = 0;
        int plantsBetween = 0;

        for (char c : corridor) {
            if (c == 'S') {
                countSeats++;
                if (countSeats == 3) {
                    ways = (ways * (plantsBetween + 1)) % MOD;
                    countSeats = 1;
                    plantsBetween = 0;
                }
            } else if (countSeats == 2) {
                plantsBetween++;
            }
        }

        return ways;
    }
};
