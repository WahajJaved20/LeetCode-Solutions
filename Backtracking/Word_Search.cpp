class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        int ROWS = board.size();
        int COLS = board[0].size();
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(board[i][j] == word[0]){
                    recur(i,j,ROWS,COLS,word,0,board,found);
                }
                if(found){
                    break;
                }
            }
            if(found){
                break;
            }
        }
        return found;
    }
    void recur(int i,int j,int& ROWS,int& COLS,string& word,int index,vector<vector<char>>& board,bool& found){
        if(index == word.size()-1){
            found = true;
            return;
        }
        if(i<0 || j<0 || found){
            return;
        }
        if(i>=ROWS || j>=COLS){
            return;
        }
        if(word[index] != board[i][j]){
            return;
        }
        char c = board[i][j];
        board[i][j] = '#';
        if(i+1 < ROWS && board[i+1][j] == word[index+1]){
            recur(i+1,j,ROWS,COLS,word,index+1,board,found);
        }
        if(j+1 < COLS && board[i][j+1] == word[index+1]){
            recur(i,j+1,ROWS,COLS,word,index+1,board,found);
        }
        if(i-1 >= 0 && board[i-1][j] == word[index+1]){
            recur(i-1,j,ROWS,COLS,word,index+1,board,found);
        }
        if(j-1 >= 0 && board[i][j-1] == word[index+1]){
            recur(i,j-1,ROWS,COLS,word,index+1,board,found);
        }
        board[i][j] = c;
    }
};
