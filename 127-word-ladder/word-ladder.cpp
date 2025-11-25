class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& arr) {
        queue<pair<string,int>> q;
        unordered_set<string> st(arr.begin(),arr.end());
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord)return steps;
            int n = word.length();

            for(int it = 0;it<n;it++){
                char c = word[it];
                for(char i = 'a';i <= 'z';i++){
                    word[it] = i;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[it] = c;
            }
        }
        return 0;
    }
};
