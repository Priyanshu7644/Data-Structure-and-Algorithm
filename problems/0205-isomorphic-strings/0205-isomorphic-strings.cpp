class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> sToT, tToS;
        
        for (int i = 0; i < s.length(); ++i) {
            char a = s[i], b = t[i];

            if (sToT.count(a)) {
                if (sToT[a] != b) return false;
            } else {
                sToT[a] = b;
            }

            if (tToS.count(b)) {
                if (tToS[b] != a) return false;
            } else {
                tToS[b] = a;
            }
        }

        return true;
    }
};