class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        dfs(n, 0, 0, curr, result);
        return result;
    }

private:
    void dfs(int n, int left, int right, string& curr, vector<string>& result) {
        if (left == n && right == n) {
            result.push_back(curr);
            return;
        }

        if (left < n) {
            curr.push_back('(');
            dfs(n, left + 1, right, curr, result);
            curr.pop_back();
        }

        if (right < left) {
            curr.push_back(')');
            dfs(n, left, right + 1, curr, result);
            curr.pop_back();
        }
    }
};

