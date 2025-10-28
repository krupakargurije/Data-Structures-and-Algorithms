class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();

        if (n < totalLen) return ans;

        // Frequency map for all words
        unordered_map<string, int> wordFreq;
        for (auto &w : words) wordFreq[w]++;

        // Try each possible offset (important for overlapping windows)
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> seen;

            // Slide window of size wordLen
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string w = s.substr(right, wordLen);

                // Valid word?
                if (wordFreq.count(w)) {
                    seen[w]++;
                    count++;

                    // Too many occurrences? move left pointer
                    while (seen[w] > wordFreq[w]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // All words matched
                    if (count == wordCount) {
                        ans.push_back(left);
                    }
                } else {
                    // Reset window if invalid word
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};
