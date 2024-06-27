class Solution {
public:
// whether the element to be put is to safe or not
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==val || board[row][i]==val){
                return false;
            }
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n=board.size();
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    for(int val='1';val<='9';val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col]=val;
                            // RECURSIVE CALL
                            bool furtherPossible=solve(board);
                            if(furtherPossible){
                                return true;
                            }else{
                                // BACKTRACKING
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
