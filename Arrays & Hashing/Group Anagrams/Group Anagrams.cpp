class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }
        vector<vector<string>> result;
        for (auto &pair : map) {
            result.push_back(pair.second);
        }
        return result;
    }
};
