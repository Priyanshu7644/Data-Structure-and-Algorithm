class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> t;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            t.push_back(word);
        }

        if (pattern.length() != t.size()) {
            return false;
        }

        unordered_map<char, string> smp;
        unordered_map<string, char> tmp;

        for (int i = 0; i < pattern.length(); i++) {
            if (smp.count(pattern[i])) {
                if (smp[pattern[i]] != t[i]) {
                    return false;
                }
            } else {
                smp[pattern[i]] = t[i];
            }

            if (tmp.count(t[i])) {
                if (tmp[t[i]] != pattern[i]) {
                    return false;
                }
            } else {
                tmp[t[i]] = pattern[i];
            }
        }

        return true;
    }
};