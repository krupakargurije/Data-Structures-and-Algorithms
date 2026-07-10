class Solution {
  public:
    int getCount(int n) {
        
        while (n % 2 == 0)
            n /= 2;

        int oddDivisors = 1;

        for (int i = 3; i * i <= n; i += 2) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            oddDivisors *= (cnt + 1);
        }

        if (n > 1)
            oddDivisors *= 2;
        return oddDivisors - 1;
    }
};