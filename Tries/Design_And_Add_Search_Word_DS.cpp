class TrieNode{
    public:
        map<char,TrieNode*> children;
        bool endOfWord;
        TrieNode(){
            endOfWord = false;
        }
};
class WordDictionary {
    TrieNode* root;
    bool searchInNode(string& word, int i, TrieNode* node) {
        if (node == NULL) {
            return false;
        }
        if (i == word.size()) {
            return node->endOfWord;
        }
        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->children[word[i]]);
        }
        for (const auto& pair : node->children) {
            if (searchInNode(word, i + 1, node->children[pair.first])) {
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            if(!curr->children[word[i]]){
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return searchInNode(word,0,this->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
