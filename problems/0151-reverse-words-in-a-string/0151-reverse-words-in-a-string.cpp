class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Split the string into words
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Build the reversed string
        reverse(words.begin(), words.end());
        
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += ' ';
        }
        
        return result;
    }
};