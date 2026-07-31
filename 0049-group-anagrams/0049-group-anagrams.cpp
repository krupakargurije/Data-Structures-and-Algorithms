class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mp;
        int n = strs.size();
        
        for(string str : strs){
            vector<int> fr(26 , 0);

            for(char c : str)
                fr[c - 'a']++;
            
            string key = "";
            for(int x : fr){
                key += '#';
                key += x;
            }

            mp[key].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};