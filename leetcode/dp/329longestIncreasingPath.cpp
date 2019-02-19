//
// Created by yin on 2019-02-09.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = recur(matrix, i, j, dp);
        res = max(res, dp[i][j]);
      }
    }
    return res;
  }

  vector<int> ia = {-1, 0, 0, 1};
  vector<int> ja = {0, -1, 1, 0};

  int recur(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j]) return dp[i][j];
    int res = 1;
    for (int k = 0; k < 4; k++) {
      int ni =i+ ia[k];
      int nj =j+ ja[k];//todo why || matrix[ni][nj] >= matrix[i][j]
      if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size() || matrix[ni][nj] >= matrix[i][j]) {
        continue;
      }
//      int max1 = recur(matrix, ni, nj, dp);
//      dp[i][j] = max(dp[i][j], max1);
      res = max(res,recur(matrix, ni, nj, dp)+1);
    }
    dp[i][j] = res;
    return res;
//    // if calculated before, no need to do it again
//    if (cache[x][y]) return cache[x][y];
//    int res = 1;
//    for (int i=0; i<4; i++) {
//      int nx = x + dr[i];
//      int ny = y + dc[i];
//      // if out of bond OR current cell value larger than previous cell value.
//      if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() ||
//          matrix[nx][ny] >= matrix[x][y]) continue;
//      res = max(res, dfs(matrix, nx, ny, cache) + 1);
//    }
//    return cache[x][y] = res;

//    if (dp[i][j]) return dp[i][j];
//    int res = 0;
//    for (int k = 0; k < 4; k++) {
//      int ni =i+ dr[k];
//      int nj =j+ dc[k];
//      if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size()
//          || matrix[ni][nj] > matrix[i][j]){
//        continue;
//      }
//      int max1 = recur(matrix, ni, nj, dp);
//      dp[i][j] = max(dp[i][j], max1);
//      res = max(res,dp[i][j]);
//    }
//    return res;
  }

public:
  const int dr[4] = { 1, 0, -1, 0 };
  const int dc[4] = { 0, -1, 0, 1 };

  int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& cache) {
    // if calculated before, no need to do it again
    if (cache[x][y]) return cache[x][y];
    int res = 1;
    for (int i=0; i<4; i++) {
      int nx = x + dr[i];
      int ny = y + dc[i];
      // if out of bond OR current cell value larger than previous cell value.
      if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() ||
          matrix[nx][ny] >= matrix[x][y]) continue;
      res = max(res, dfs(matrix, nx, ny, cache) + 1);
    }
    return cache[x][y] = res;
  }

  int longestIncreasingPath2(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> cache(m, vector<int>(n, 0));
    int res = 0;
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
        cache[i][j] = dfs(matrix, i, j, cache);
        res = max(res, cache[i][j]);
      }
    }
    return res;
  }


  int longestIncreasingPath3(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (!rows) return 0;
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    std::function<int(int, int)> dfs = [&] (int x, int y) {
      if (dp[x][y]) return dp[x][y];
      vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
      for (auto &dir : dirs) {
        int xx = x + dir[0], yy = y + dir[1];
        if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
        if (matrix[xx][yy] <= matrix[x][y]) continue;
        dp[x][y] = std::max(dp[x][y], dfs(xx, yy));
      }
      return ++dp[x][y];
    };

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        ret = std::max(ret, dfs(i, j));
      }
    }

    return ret;
  }
};

int main() {
  vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
  Solution s;
  cout<<s.longestIncreasingPath(matrix)<<endl;
  return 0;
}