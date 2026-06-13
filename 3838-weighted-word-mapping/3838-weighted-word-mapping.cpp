class Solutions{
    public:
    string helper(vector<string>& words, vector<int>& weights){
        string ans;
        
        for(string str : words){
            int temp = 0;
            for(char c : str){
                temp += weights[c - 'a'];
            }

            int mod = temp % 26;
            char c = 'z' - mod;
            ans.push_back(c);
        }
        return ans;
    }
};
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        Solutions s;
        string ans = s.helper(words,weights);
        return ans;
    }
};