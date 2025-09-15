class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenSet;
        for(char ch : brokenLetters) {
            brokenSet.insert(ch);
        }
        
        int count = 0;
        stringstream ss(text);
        string word;
        
        while(ss >> word) {
            bool canType = true;
            for(char ch : word) {
                if(brokenSet.find(ch) != brokenSet.end()) {
                    canType = false;
                    break;
                }
            }
            if(canType) {
                count++;
            }
        }
        
        return count;
    }
};