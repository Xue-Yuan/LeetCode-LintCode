/*
    Given a start position and an target position on the grid. 
        You can move up,down,left,right from one node to another 
        adjacent one on the grid. However there are some walls on 
        the grid that you cannot pass. Now find the shortest path 
        from the start to the target. 
    
    (This is easy done by BFS) 
    Extend. If you can remove three walls, then what is the shortest 
        path from start to the target. (I have no ideal except for 
        enumerate all the possibility of three walls. It must be the 
        silly solution.) Does anyone have any idea?

https://www.careercup.com/question?id=5681111363485696
*/
class Solution 
{
public:
    int gridShortestPath(vector<vector<int>> &grid, pair<int, int> start, int target)
    {
        if(grid.empty() || grid[0].empty()) return 0;

        int row = grid.size(), col = grid.front().size();
        queue<pair<int, int>> cur;
        cur.push(start);
        int cnt = 0;
        while (!cur.empty())
        {
            queue<pair<int, int>> nxt;
            while (!cur.empty())
            {
                auto p = cur.front(); cur.pop();
                if (grid[p.first][p.second] == target) return cnt;
                grid[p.first][p.second] = -1;
                
                if (p.first+1 < row && grid[p.first+1][p.second] != -1) 
                    nxt.push({p.first+1, p.second});
                if (p.first-1 >= 0 && grid[p.first-1][p.second] != -1) 
                    nxt.push({p.first-1, p.second});
                if (p.second+1 < col && grid[p.first][p.second+1] != -1) 
                    nxt.push({p.first, p.second+1});
                if (p.second-1 >= 0 && grid[p.first][p.second-1] != -1) 
                    nxt.push({p.first, p.second-1});
            }
            cnt++;
            cur = move(nxt);
        }
        return -1;
    }
};


//Some guy's post for the extend.
struct Tuple4 {
  int dis, x, y, wall;
};

inline bool operator< (const Tuple4& lhs, const Tuple4& rhs){
    if(lhs.dis != rhs.dis) return lhs.dis > rhs.dis;
    else return lhs.wall < rhs.wall;
}

vector<pair<int, int>> solve(vector<vector<int>> maze, int sx, int sy, int dx, int dy, int w) {
  int n = maze.size(), m = maze[0].size();
  bool visited[n][m][w + 1];
  int dis[n][m][w + 1];
  int min_dis[n][m], prev[n][m][2];
  for(int i = 0; i < n; i ++)
    for(int j = 0; j < m; j ++) {
      min_dis[i][j] = INT_MAX;
      prev[i][j][0] = prev[i][j][1] = -1;
      for(int k = 0; k <= w; k ++) {
        visited[i][j][k] = false;
        dis[i][j][k] = INT_MAX;
      }
    }

  priority_queue<Tuple4> pq;
  pq.push(Tuple4{0, sx, sy, w});
  dis[sx][sy][w] = 0;
  min_dis[sx][sy] = 0;
  int ddx[] = {0, 0, -1, 1};
  int ddy[] = {-1, 1, 0, 0};
  while(!pq.empty()) {
    Tuple4 node = pq.top();
    pq.pop();
    visited[node.x][node.y][node.wall] = true;
    if(node.x == dx && node.y == dy) break;
    for(int i = 0; i < 4; i ++) {
      int nx = node.x + ddx[i];
      int ny = node.y + ddy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      else if(maze[nx][ny] == 0) { // not wall
        if(visited[nx][ny][node.wall])
          continue;
        else {
          if(dis[nx][ny][node.wall] <= node.dis + 1) continue;
          dis[nx][ny][node.wall] = node.dis + 1;
          pq.push(Tuple4{node.dis + 1, nx, ny, node.wall});
          if(dis[nx][ny][node.wall] < min_dis[nx][ny]) {
            min_dis[nx][ny] = dis[nx][ny][node.wall];
            prev[nx][ny][0] = node.x, prev[nx][ny][1] = node.y;
            cout << nx << "," << ny << " : " << node.x << "," << node.y << endl;
          }
        }
      } else { // wall
        if(node.wall == 0) continue;
        else if(visited[nx][ny][node.wall-1]) continue;
        else {
          if(dis[nx][ny][node.wall - 1] <= node.dis + 1) continue;
          dis[nx][ny][node.wall - 1] = node.dis + 1;
          pq.push(Tuple4{node.dis + 1, nx, ny, node.wall - 1});
          if(dis[nx][ny][node.wall - 1] < min_dis[nx][ny]) {
            min_dis[nx][ny] = dis[nx][ny][node.wall - 1];
            prev[nx][ny][0] = node.x, prev[nx][ny][1] = node.y;
            cout << nx << "," << ny << " : " << node.x << "," << node.y << endl;
          }
        }
      }
    }
  }
  vector<pair<int, int>> ret;
  do {
    ret.push_back(make_pair(dx, dy));
    int tdx = prev[dx][dy][0];
    int tdy = prev[dx][dy][1];
    dx = tdx, dy = tdy;
  } while(dx != -1 && dy != -1);
  return ret;
}

int main() {
  vector<vector<int>> maze = {
    {0, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0}
  };

  vector<pair<int, int>> ans = solve(maze, 0, 0, 0, 5, 3);
  for(auto n : ans) {
    cout << n.first << " " << n.second << endl;
  }
  return 0;
}