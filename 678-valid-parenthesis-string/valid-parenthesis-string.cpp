class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open; // indices of '('
        stack<int> star; // indices of '*'

        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') open.push(i);
            else if (s[i] == '*') star.push(i);
            else { // s[i] == ')'
                if (!open.empty()) open.pop();
                else if (!star.empty()) star.pop();
                else return false; // no match for ')'
            }
        }

        // Match remaining '(' with later '*' used as ')'
        while (!open.empty()) {
            if (star.empty()) return false;
            if (star.top() < open.top()) return false; // '*' must come after '('
            star.pop();
            open.pop();
        }

        return true;
    }
};
