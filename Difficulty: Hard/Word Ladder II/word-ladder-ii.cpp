// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord,
    string endWord,vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<vector<string>> ans;
        vector<string> used;
        used.push_back(beginWord);
        int level = 0;

        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();

            if(vec.size() > level){
                level++;
                for(auto i: used){
                    st.erase(i);
                }
                used.clear();
            }

            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }


            for(int i = 0;i<word.size();i++){
                char org = word[i];
                for(char c = 'a';c<='z';c++){
                    word[i] = c;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push({vec});
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = org;
            }

        }
        return ans;
        
    }
};