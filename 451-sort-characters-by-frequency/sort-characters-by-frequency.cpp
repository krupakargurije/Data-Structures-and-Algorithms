class Solution {
public:
    string frequencySort(string s) {
        map<char , int>mp;

        for(char c : s){
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto [c , freq] : mp){
            pq.push({freq , c});
        }

        string ans = "";

        while(!pq.empty()){
            auto [freq , c] = pq.top();pq.pop();

            string str = string(freq , c);
            ans += str;
        }
        return ans;
    }
};