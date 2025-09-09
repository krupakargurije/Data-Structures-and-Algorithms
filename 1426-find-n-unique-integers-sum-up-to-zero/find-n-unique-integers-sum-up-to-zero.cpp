class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> l;

        int pairs = n / 2;
        for (int i = 1; i <= pairs; ++i) {
            l.push_back(i);
            l.push_back(-i);
        }

        if (n % 2 == 1) {
            l.push_back(0);
        }

        return l;
    }
};