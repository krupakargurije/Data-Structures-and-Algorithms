class Solution {
public:
    int countOdds(int l, int h) {
        return (h - l >> 1) + (l & 1 | h & 1);
    }
};