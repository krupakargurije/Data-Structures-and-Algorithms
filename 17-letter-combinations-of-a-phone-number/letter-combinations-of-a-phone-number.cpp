class Solution {
    private:
    vector<string>mp{
        "",
        "",
        "abc", //1
        "def", //2
        "ghi", //3
        "jkl", //4
        "mno", //5
        "pqrs", //6
        "tuv", //7
        "wxyz" //8
    };
    vector<string>ans;

    void helper(string  &digits, int idx , string curr){
        if(idx == digits.length()){
            ans.push_back(curr);
            return;
        }

        string keys = mp[digits[idx] - '0'];
        for(char c : keys){
            curr.push_back(c);
            helper(digits , idx + 1 , curr);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        helper(digits , 0 , "");
        return ans;
    }
};