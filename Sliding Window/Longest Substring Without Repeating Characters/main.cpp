class Solution {
public:
int characterReplacement(string s, int k) {
int n = s.size();
int freq[26] = {0}; // frequency of characters
int left = 0, right = 0; // sliding window boundaries
int maxCount = 0, maxLength = 0; // result variables
while (right < n) {
freq[s[right] - 'A']++; // increment frequency of current character
maxCount = max(maxCount, freq[s[right] - 'A']); // update max frequency
if (right - left + 1 - maxCount > k) { // if number of replacements needed > k
freq[s[left] - 'A']--; // decrement frequency of left character
left++; // move sliding window to right
}
maxLength = max(maxLength, right - left + 1); // update max length of substring
right++; // move sliding window to right
}
return maxLength;
}
};
