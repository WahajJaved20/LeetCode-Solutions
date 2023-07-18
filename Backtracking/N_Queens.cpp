class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        map<int,bool> cols,posDiag,negDiag;
        //positive diagonal = r + c
        // negative diagonal = r -c
        vector<vector<string>> res;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        backtrack(0,n,board,res,cols,posDiag,negDiag);
        return res;
    }
    void backtrack(int r, int n, vector<vector<char>>& board, vector<vector<string>>& res,map<int,bool>& cols,map<int,bool>& posDiag,map<int,bool>& negDiag){
        if(r == n){
            string temp = "";
            vector<string> t;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp += board[i][j];
                }
                t.push_back(temp);
                temp = "";
            }
            res.push_back(t);
            return;
        }
        for(int c=0;c<n;c++){
            if(cols[c] || posDiag[c+r] || negDiag[r-c]){
                continue;
            }
            cols[c] = true;
            posDiag[r + c] = true;
            negDiag[r - c] = true;
            board[r][c] = 'Q';
            backtrack(r+1,n,board,res,cols,posDiag,negDiag);
            cols[c] = false;
            posDiag[r + c] = false;
            negDiag[r - c] = false;
            board[r][c] = '.';
        }
    }
};
