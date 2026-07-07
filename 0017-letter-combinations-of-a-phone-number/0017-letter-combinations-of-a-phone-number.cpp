class Solution {
    private:
    vector<string> ans;
    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void helper(string &digits , int idx , string curr){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for(char c : letters){
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

// input =                 234
        
//             2 = abc     3 = def     4 = ghi
//                  
//         letters start with 
//         a
//         b
//         c

        


























