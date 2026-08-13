class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if(n % k > 1)return false;

        map<int , int>mp;
        for(int i : hand){
            mp[i]++;
        }

        for(auto &[number , count] : mp){

            if(count == 0)continue;

            for(int i = 1;i<k;i++){
                int req = number + i;

                if(mp[req] < count)return false;
                mp[req] -= count;

                if(mp[req] == 0)mp.erase(req);
            }
        }
        return true;
    }
};