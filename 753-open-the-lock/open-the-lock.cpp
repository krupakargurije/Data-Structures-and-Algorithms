class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> blocks(deadends.begin(), deadends.end());
        if(blocks.count("0000")) return -1;

        queue<pair<string,int>> q;
        q.push({"0000",0});

        unordered_set<string> vis;
        vis.insert("0000");

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            string currStr = it.first;
            int steps = it.second;

            if(currStr == target)
                return steps;

            for(int i = 0; i < 4; i++){
                for(int delta : {-1,1}){
                    
                    int newDig = (currStr[i] - '0' + delta + 10) % 10;
                    string newComb = currStr;
                    newComb[i] = '0' + newDig;
                    
                    if(!blocks.count(newComb) && !vis.count(newComb)){
                        vis.insert(newComb);
                        q.push({newComb, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};
