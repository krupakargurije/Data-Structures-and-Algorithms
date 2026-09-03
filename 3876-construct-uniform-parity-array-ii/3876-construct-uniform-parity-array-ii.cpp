class Solutions{
    public:
    bool helper(vector<int>& a){
        int mn = INT_MAX;
        bool odd = false;

        for (int x : a) {
            mn = min(mn, x);
            if (x % 2 == 1) odd = true;
        }

        if (mn % 2 == 1) return true;
        if (!odd) return true;

        return false;
    }
};
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        Solutions s;
        bool ans = s.helper(nums1);
        return ans;
    }
};