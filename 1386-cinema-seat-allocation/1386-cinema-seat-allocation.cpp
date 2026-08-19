class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , unordered_set<int>>mp;
        for(auto &it : reservedSeats){
            if(it[1] >= 2 && it[1] <= 9)
                mp[it[0]].insert(it[1]);
        }

        int ans = n * 2;
        for(auto &[row , seat] : mp){
            ans -= 2;

            bool left = true;
            bool right = true;
            bool middle = true;

            for(int i = 2;i<=5;i++){
                if(seat.count(i)){
                    left = false;
                    break;
                }
            }

            for(int i = 4;i<=7;i++){
                if(seat.count(i)){
                    middle = false;
                    break;
                }
            }

            for(int i = 6;i<=9;i++){
                if(seat.count(i)){
                    right = false;
                    break;
                }
            }

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }
        return ans;
    }
};