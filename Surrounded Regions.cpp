/*
    Given a 2D board containing 'X' and 'O', capture all regions 
        surrounded by 'X'.

    A region is captured by flipping all 'O's into 'X's in that 
        surrounded region.

    For example,
        X X X X
        X O O X
        X X O X
        X O X X
    
    After running your function, the board should be:
        X X X X
        X X X X
        X X X X
        X O X X
*/

class Solution 
{
private:
    const char VISITED = '\0';
public:    
    void solve(vector<vector<char>> &board)
    {
        if (board.empty() || board[0].empty()) return;
        int N = (int)board.size(), M = (int)board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || j == 0 || i == N-1 || j == M-1)
                    bfs(board, i, j); // you may call dfs or bfs here!
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = (board[i][j] == VISITED) ? 'O' : 'X';
    }
    
    void dfs(vector<vector<char>> &board, int row, int col) 
    {
        if (board[row][col] != 'O') return;

        board[row][col] = VISITED;

        //Do not go to the boundaries again, otherwise it will cause stack 
        //  overflow in the last large test case.
        if (row + 1 < board.size())
            dfs(board, row+1, col);
        if (row > 1)
            dfs(board, row-1, col);
        if (col + 1 < board[0].size())
            dfs(board, row, col+1);
        if (col > 1)
            dfs(board, row, col-1);
    }

    void bfs(vector<vector<char>> &board, int r, int c)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= board.size() || j < 0 || j > board[0].size()) continue;
            if (board[i][j] != 'O') continue;
            board[i][j] = VISITED;
            q.push({i + 1, j});
            q.push({i - 1, j});
            q.push({i, j + 1});
            q.push({i, j - 1});
        }
    }
};