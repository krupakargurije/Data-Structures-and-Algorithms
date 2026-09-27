class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> link(n) , st;

        for(int i = 0;i<n;i++){
            if(s[i] == '(')
                st.push_back(i);
            else if(s[i] == ')'){
                link[i] = st.back();
                link[link[i]] = i;
                st.pop_back();
            }
        }

        string ans = "";

        for(int i = 0 , dir = 1;i<n;i+= dir){
            if(s[i] >= 'a'){
                ans += s[i];
            }
            else{
                i = link[i];
                dir = -dir;
            }
        }
        return ans;
    }
};
