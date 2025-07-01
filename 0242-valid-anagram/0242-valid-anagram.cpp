class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> strS;
        unordered_map<char, int> strT;
        for(char c: s) {
            strS[c]++;
        }
        for(char c: t) {
            strT[c]++;
        }
        if(strS == strT) return true;
        return false;
    }
};


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//        vector<int> freq(26, 0);
//        for(int i=0; i<s.size(); i++) {
//         freq[s[i] - 'a']++;
//         freq[t[i] - 'a']--;
//        }
//        for(int i=0; i<freq.size(); i++) {
//         if(freq[i] != 0) return false;
//        }
//        return true;
//     }
// };




// // class Solution {
// // public:
// //     bool isAnagram(string s, string t) {
// //        sort(s.begin(), s.end()); 
// //        sort(t.begin(), t.end()); 
// //        if(s==t) return true;
// //        else return false;
// //     }
// // };