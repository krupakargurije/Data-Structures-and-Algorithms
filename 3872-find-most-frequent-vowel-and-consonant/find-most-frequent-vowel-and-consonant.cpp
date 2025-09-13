class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        for(int i: s){
            mp[i]++;
        }
        int maxVowels = 0;
        int maxCons = 0;
        for(auto &i : mp){
            int temp = i.second;
            if(i.first == 'a' || i.first == 'e' || i.first == 'i' || i.first == 'o' || i.first == 'u'){
                maxVowels = max(maxVowels,temp);
            }
            else{
                maxCons = max(maxCons,temp);
            }
        }
        return maxCons + maxVowels;
    }
};