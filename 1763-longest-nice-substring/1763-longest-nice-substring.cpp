class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2)
            return "";

        unordered_set<char> chars(s.begin(), s.end());

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            char opposite = islower(c)
                ? toupper(c)
                : tolower(c);

            // This character prevents any nice substring
            // from containing s[i].
            if (!chars.count(opposite)) {
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));

                // Use '>' so that ties keep the earlier occurrence.
                return left.size() >= right.size() ? left : right;
            }
        }

        // Every character has both cases.
        return s;
    }
};