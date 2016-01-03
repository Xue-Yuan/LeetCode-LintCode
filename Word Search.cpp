/*
    Given a 2D board and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent 
        cell, where "adjacent" cells are those horizontally or vertically 
        neighboring. The same letter cell may not be used more than once.

    For example,
        Given board =

        [
          ['A','B','C','E'],
          ['S','F','C','S'],
          ['A','D','E','E']
        ]

        word = "ABCCED", -> returns true,
        word = "SEE", -> returns true,
        word = "ABCB", -> returns false.
*/

class Solution
{
private:
    bool exist(vector<vector<char>> &board, string &word, int cur, int row, int col)
    {
        if(cur == word.size()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[cur]) return false;
        
        char save = board[row][col];
        board[row][col] = VISITED;
        
        if (exist(board, word, cur + 1, row + 1, col)) return true;
        if (exist(board, word, cur + 1, row - 1, col)) return true;
        if (exist(board, word, cur + 1, row, col + 1)) return true;
        if (exist(board, word, cur + 1, row, col - 1)) return true;
        
        board[row][col] = save;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (board.empty() || board[0].empty()) return word.empty(); 
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (exist(board, word, 0, i, j)) return true;
        
        return false;
    }
private:
    const char VISITED = '\0'; 
};
