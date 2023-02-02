//GO OUT OF TIME
class WordDictionary {
public:
    struct TrieNode {
        bool isWord;
        vector<TrieNode*> children;
        TrieNode() : isWord(false), children(26, nullptr) {}
    };
    
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int index = c - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return search(root, word, 0);
    }
    
    bool search(TrieNode* node, string word, int index) {
        if (!node) return false;
        if (index == word.size()) return node->isWord;
        if (word[index] != '.') {
            int nextIndex = word[index] - 'a';
            return search(node->children[nextIndex], word, index + 1);
        } else {
            for (int i = 0; i < 26; i++) {
                if (search(node->children[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
    }
};
