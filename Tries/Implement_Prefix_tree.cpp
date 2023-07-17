class TrieNode{
    public:
        map<char,TrieNode*> children;
        bool endOfWord;
        TrieNode(){
            endOfWord = false;
        }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            if(!curr->children[word[i]]){
                return false;
            }
            curr = curr->children[word[i]];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0;i<prefix.length();i++){
            if(!curr->children[prefix[i]]){
                return false;
            }
            curr = curr->children[prefix[i]];
        }
        return curr->children.size() >= 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
