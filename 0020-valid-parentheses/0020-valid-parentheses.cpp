class Solution {
public:
    bool isValid(string s) {
        int n = s.length();

        stack<char>st;

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
                continue;
            }

            if(st.empty())return false;
            char curr = st.top();

            if(st.empty() || 
                c == ')' && curr != '(' || 
                c == ']' && curr != '[' ||
                c == '}' && curr != '{'
            ) return false;

            st.pop();
        }
        return st.empty();
    }
};


// ( [ ) )

// ( [ -> false

// st.empty()


//  ))
