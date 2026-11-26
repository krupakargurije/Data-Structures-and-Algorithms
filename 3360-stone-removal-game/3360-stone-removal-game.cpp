class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        bool bob = false;
        int t = 10;

        while(n >= t){
            n -= t;
            alice ? alice = false : alice = true;
            bob ? bob = false : bob = true;
            t--;
        }
        if(!alice)
            return true;
        return false;
    }
};