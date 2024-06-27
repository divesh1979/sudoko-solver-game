#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // whether the element to be put is to safe or not
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == val || board[row][i] == val) {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(row, col, board, val)) {
                            board[row][col] = val;
                            // RECURSIVE CALL
                            bool furtherPossible = solve(board);
                            if (furtherPossible) {
                                return true;
                            } else {
                                // BACKTRACKING
                                board[row][col] = '.';
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

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution().solveSudoku(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
