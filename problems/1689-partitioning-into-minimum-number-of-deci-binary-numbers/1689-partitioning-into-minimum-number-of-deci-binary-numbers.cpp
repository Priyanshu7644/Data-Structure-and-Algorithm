class Solution {
public:
    int minPartitions(string n) {
        char maxDigit = '0';
        for (char c : n) {
            if (c > maxDigit) {
                maxDigit = c;
            }
            if (maxDigit == '9') return 9;
        }
        return maxDigit - '0';
    }
};