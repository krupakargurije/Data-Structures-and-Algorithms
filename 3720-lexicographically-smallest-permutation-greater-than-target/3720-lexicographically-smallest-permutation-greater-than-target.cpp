class Solution {
    private:
    string ans = "";
    vector<int>mp;

    bool helper(string &target , int idx , bool greater , string curr){
        if(idx == target.length()){
            if(greater){
                ans = curr;
                return true;
            }
            return false;
        }

        for(char c = 'a' ; c <= 'z' ; c++){
            if(mp[c - 'a'] == 0)continue;

            if(!greater && c < target[idx])continue;

            curr.push_back(c);
            mp[c - 'a']--;

            bool isGreater = greater || target[idx] < c;

            if(helper(target , idx + 1 , isGreater , curr))
                return true;
            
            curr.pop_back();
            mp[c - 'a']++;
        }
        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.length();
        mp.assign(26 , 0);

        for(char c : s)
            mp[c - 'a']++;

        helper(target , 0 , false , "");
        return ans;
    }
};