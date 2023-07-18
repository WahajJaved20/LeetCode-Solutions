class TrieNode{
    public:
        map<char,TrieNode*> children;
        bool endOfWord;
        TrieNode(){
            endOfWord = false;
        }
};
class Trie {
public:
TrieNode* root;
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
};

class Solution {
public:
    Trie dictionary;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> res;
        if(board.size() == 0){
            return vector<string>(res.begin(),res.end());
        }
        for(int i=0;i<words.size();i++){
            dictionary.insert(words[i]);
        }
        int ROWS = board.size(), COLS = board[0].size();
        
        for(int r=0;r< ROWS;r++){
            for(int c=0;c<COLS;c++){
                dfs(r, c, dictionary.root, "",ROWS,COLS,board,res);
            }
        }
        return vector<string>(res.begin(),res.end());
    }
    void dfs(int row,int col, TrieNode* node, string word,int &ROWS,int &COLS,vector<vector<char>>& board,set<string>& res){
        if(row < 0 || col < 0){
            return;
        }
        if(row >= ROWS || col >= COLS || board[row][col] == '#'){
            return;
        }
        if(!node->children[board[row][col]]){
            return;
        }
        char cha = board[row][col];
        node = node->children[board[row][col]];
        word += board[row][col];
        if(node->endOfWord){
            res.insert(word);
        }
        board[row][col] = '#';
        dfs(row + 1, col, node, word, ROWS, COLS, board, res);
        dfs(row - 1, col, node, word, ROWS, COLS, board, res);
        dfs(row, col + 1, node, word, ROWS, COLS, board, res);
        dfs(row, col - 1, node, word, ROWS, COLS, board, res);
        board[row][col] = cha;
    }
};
