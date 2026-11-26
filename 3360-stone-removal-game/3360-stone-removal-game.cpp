class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        int t = 10;

        while(n >= t){
            n -= t;
            alice = !alice;
            t--;
        }
        if(!alice)
            return true;
        return false;
    }
};