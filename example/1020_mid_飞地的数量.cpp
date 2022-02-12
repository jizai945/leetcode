// 1020. 飞地的数量
// 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

// 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

// 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。

 

// 示例 1：


// 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// 输出：3
// 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
// 示例 2：


// 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// 输出：0
// 解释：所有 1 都在边界上或可以到达边界。
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] 的值为 0 或 1
// 通过次数30,566提交次数50,680
class Solution {
private:
    vector<vector<int> >flag;
    vector<vector<int> >visit;
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        
        if (visit[x][y]) return;
        if (flag[x][y]) return;
        if (grid[x][y] == 0) {
            // cout << x <<"*" << y << endl;
            flag[x][y] = -1;
            return;
        }

        visit[x][y] = 1;
        flag[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            dfs(grid, x+dir[i][0], y+dir[i][1]);
        }
        visit[x][y] = 0;

    }

    int numEnclaves(vector<vector<int>>& grid) {
        flag.resize(grid.size());
        visit.resize(grid.size());
        for (int k = 0; k < grid.size(); ++k){
            flag[k].resize(grid[0].size());
            visit[k].resize(grid[0].size());
        }
        for (int i = 0; i < grid.size(); i++) {
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size()-1);
        }

        for (int i = 0; i < grid[0].size(); i++) {
            dfs(grid, 0, i);
            dfs(grid, grid.size()-1, i);
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (flag[i][j] == 0 && grid[i][j]) {
                    ans++;
                    // cout << i << " " << j << endl;
                }
            }
        }


        return ans;
    }
};
