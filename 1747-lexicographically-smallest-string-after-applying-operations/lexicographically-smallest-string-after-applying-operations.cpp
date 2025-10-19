class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        string smallStr = s;

        q.push(s);
        vis.insert(s);

        while(!q.empty()){
            string curStr = q.front();
            q.pop();
            if(curStr < smallStr)smallStr = curStr;

            string added = curStr;
            for(int i = 1;i<added.size();i+=2){
                added[i] = (((added[i] - '0') + a) % 10) +'0';
            }
            if(!vis.count(added)){
                q.push(added);
                vis.insert(added);
            }

            string rotated = curStr.substr(curStr.size() - b) + curStr.substr(0, curStr.size() - b);
            if(!vis.count(rotated)){
                q.push(rotated);
                vis.insert(rotated);
            }
        }
        return smallStr;
    }
};