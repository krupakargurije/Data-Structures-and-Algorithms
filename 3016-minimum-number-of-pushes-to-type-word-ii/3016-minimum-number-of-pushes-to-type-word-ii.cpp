class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int>mp(26 , 0);

        for(int i = 0;i<n;i++){
            mp[word[i] - 'a']++;
        }
        sort(mp.begin() , mp.end() , greater<int>());

        int ans = 0;
        int count = 0;
        int x = 1;

        for(int i : mp){
            if(i == 0)
                break;
            
            if (count == 8) {
                x++;
                count = 0;
            }
            ans += x * i;
            count++;
        }
        return ans;
    }
};


// xyzxyzxyzxyz -> xyz - 4
// abcdefgh ijklmnop qrstuvwx yz  1 * 8 , 2 * 2 3 * 8 4 * 2