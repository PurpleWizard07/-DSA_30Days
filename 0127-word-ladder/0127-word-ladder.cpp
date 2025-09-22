class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0; // endWord not in list

        queue<pair<string, int>> q; // {currentWord, steps}
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) return level;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;  // change one letter
                    if (wordSet.find(temp) != wordSet.end()) {
                        q.push({temp, level + 1});
                        wordSet.erase(temp); // mark visited
                    }
                }
            }
        }

        return 0;
    }
};
