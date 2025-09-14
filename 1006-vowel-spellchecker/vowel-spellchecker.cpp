#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());

        unordered_map<string, string> caseMap;  // lowercase -> first word
        unordered_map<string, string> vowelMap; // devoweled lowercase -> first

        for (string& w : wordlist) {
            string lower = toLower(w);
            string devowel = deVowel(lower);

            if (!caseMap.count(lower))
                caseMap[lower] = w;
            if (!vowelMap.count(devowel))
                vowelMap[devowel] = w;
        }

        vector<string> ans;
        for (string& q : queries) {
            if (words.count(q)) {
                ans.push_back(q);
            } else {
                string lower = toLower(q);
                string devowel = deVowel(lower);

                if (caseMap.count(lower)) {
                    ans.push_back(caseMap[lower]);
                } else if (vowelMap.count(devowel)) {
                    ans.push_back(vowelMap[devowel]);
                } else {
                    ans.push_back("");
                }
            }
        }
        return ans;
    }

private:
    string toLower(string s) {
        for (char& c : s)
            c = tolower(c);
        return s;
    }

    string deVowel(string s) {
        for (char& c : s) {
            if (isVowel(c))
                c = '*';
        }
        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
