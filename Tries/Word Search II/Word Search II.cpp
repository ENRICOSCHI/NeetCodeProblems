class Solution {
public:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isWord(false), children() {}
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* p = root;
            for (char c : word) {
                if (!p->children.count(c)) p->children[c] = new TrieNode();
                p = p->children[c];
            }
            p->isWord = true;
        }
        return root;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, string& word, vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || !p->children.count(c)) return;
        p = p->children[c];
        word.push_back(c);
        if (p->isWord) {
            res.push_back(word);
            p->isWord = false;
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, word, res);
        if (j > 0) dfs(board, i, j - 1, p, word, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, word, res);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, word, res);
        word.pop_back();
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string word;
                dfs(board, i, j, root, word, res);
            }
        }
        return res;
    }
};
