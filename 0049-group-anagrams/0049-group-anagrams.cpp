class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto s: strs) {
            string sortWord = s;
            sort(sortWord.begin(), sortWord.end());
            map[sortWord].push_back(s);
        }
            vector<vector<string>> result;
        for (auto& pair : map) {
            result.push_back(pair.second);
        }
        return result;

    }
};