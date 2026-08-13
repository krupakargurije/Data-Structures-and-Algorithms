class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k > 0)return false;
        
        map<int , int>mp;
        for(int i : nums){ // n log n
            mp[i]++;
        }

        for(auto &[number , count] : mp){ //m = n / k -> number of partations

            if(count == 0){
                continue;
            }

            for(int i = 1;i<k;i++){  // k times -> total m * k
                int req = number + i;

                if(mp[req] < count)return false;
                mp[req] -= count;

                if(mp[number] == 0)
                    mp.erase(number);
            }
        }
        return true;
    }
};