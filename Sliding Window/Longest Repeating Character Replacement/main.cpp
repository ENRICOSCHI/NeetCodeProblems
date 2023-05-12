class Solution {
public:
int lengthOfLongestSubstring(string s) {
unordered_set<char> uniqueChars; // to store unique characters in current window
int maxLength = 0, i = 0, j = 0; // i and j are indices of current window

    while (j < s.size()) {
        if (uniqueChars.find(s[j]) == uniqueChars.end()) {
            // if s[j] is not in the window, add it
            uniqueChars.insert(s[j]);
            j++;
            maxLength = max(maxLength, j - i); // update max length if needed
        } else {
            // if s[j] is already in the window, remove s[i] until s[j] is removed
            uniqueChars.erase(s[i]);
            i++;
        }
    }

    return maxLength;
}
};
