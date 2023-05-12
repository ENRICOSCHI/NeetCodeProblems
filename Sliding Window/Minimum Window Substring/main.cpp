class Solution {
public:
string minWindow(string s, string t) {
int m = s.size(), n = t.size();
if (m < n) return "";
unordered_map<char, int> countT, countWindow;
// fill countT
for (char c : t) countT[c]++;
// sliding window algorithm
int left = 0, right = 0, countMatch = 0, windowLength = INT_MAX, windowStart = 0;
while (right < m) {
char c = s[right];
right++;
// update countWindow
if (countT.find(c) != countT.end()) {
countWindow[c]++;
if (countWindow[c] == countT[c]) countMatch++;
}
// shrink the window from left if possible
while (countMatch == countT.size()) {
// update the window size and start position
if (right - left < windowLength) {
windowLength = right - left;
windowStart = left;
}
char c = s[left];
left++;
// update countWindow
if (countT.find(c) != countT.end()) {
if (countWindow[c] == countT[c]) countMatch--;
countWindow[c]--;
}
}
}
return windowLength == INT_MAX ? "" : s.substr(windowStart, windowLength);
}
};
