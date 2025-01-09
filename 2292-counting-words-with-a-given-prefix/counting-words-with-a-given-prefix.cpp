class Solution {
public:
    // trie-solution
    class TrieNode {
        public:
            char value;
            unordered_map<int, TrieNode*> children;
            int count;

            TrieNode(char val) {
                this->value = val;
                count = 0;
            }
    };

    void insert(TrieNode* root, string& word, int index) {
        if(index >= word.size()) {
            return;
        }

        char ch = word[index];

        TrieNode* child;
        if(root->children[ch] != NULL) {
            child = root->children[ch];
        }
        else {
            child = new TrieNode(ch);
            root->children[ch] = child;
        }

        root->children[ch]->count++;

        insert(child, word, index + 1);
    }

    int countStr(TrieNode* root, string& target, int index) {
        if(index >= target.size()) return root->count;

        char ch = target[index];

        TrieNode* child;
        if(root->children[ch] != NULL) {
            child = root->children[ch];
        }
        else return 0;

        return countStr(child, target, index + 1);
    }

    int prefixCount(vector<string>& words, string pref) {
        TrieNode* root = new TrieNode('-');
        for(auto val : words) {
            insert(root, val, 0);
        }

        return countStr(root, pref, 0);
    }
};