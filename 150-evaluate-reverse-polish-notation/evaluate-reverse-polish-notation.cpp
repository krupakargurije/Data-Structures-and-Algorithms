class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(string &c : tokens){

            if(c == "+"){
                int first = st.top();st.pop();
                int second = st.top();st.pop();
                st.push(first+second);
            }
            else if(c == "-"){
                int first = st.top();st.pop();
                int second = st.top();st.pop();
                st.push(second - first);
            }
            else if(c == "*"){
                int first = st.top();st.pop();
                int second = st.top();st.pop();
                st.push(first * second);
            }
            else if(c == "/"){
                int first = st.top();st.pop();
                int second = st.top();st.pop();
                st.push(second / first);
            }
            else
                st.push(stoi(c));
        }
        return st.top();
    }
};