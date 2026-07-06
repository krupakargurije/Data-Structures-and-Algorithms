class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        deque<string> arr;
        string str = "";

        for(char c : s){
            if(c == ' '){
                if(!str.empty()){
                    arr.push_front(str);
                    str = "";
                }
            }
            else str += c;
        }

        if (!str.empty()) arr.push_front(str);

        string ans;
        for(string s : arr){
            ans += s + " ";
        }

        if(!ans.empty())ans.pop_back();
        return ans;
    }
};