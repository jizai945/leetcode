// 1765. 地图中的最高点
// 给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

// 如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
// 如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
// 你需要按照如下规则给每个单元格安排高度：

// 每个格子的高度都必须是非负的。
// 如果一个格子是是 水域 ，那么它的高度必须为 0 。
// 任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
// 找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

// 请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。

 

// 示例 1：



// 输入：isWater = [[0,1],[0,0]]
// 输出：[[1,0],[2,1]]
// 解释：上图展示了给各个格子安排的高度。
// 蓝色格子是水域格，绿色格子是陆地格。
// 示例 2：



// 输入：isWater = [[0,0,1],[1,0,0],[0,0,0]]
// 输出：[[1,1,0],[0,1,1],[1,2,2]]
// 解释：所有安排方案中，最高可行高度为 2 。
// 任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。
 

// 提示：

// m == isWater.length
// n == isWater[i].length
// 1 <= m, n <= 1000
// isWater[i][j] 要么是 0 ，要么是 1 。
// 至少有 1 个水域格子。
// 通过次数9,342提交次数14,841

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); // -1 表示该格子尚未被访问过
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.emplace(i, j); // 将所有水域入队
                }
            }
        }
        while (!q.empty()) {
            auto &p = q.front();
            for (auto &dir : dirs) {
                int x = p.first + dir[0], y = p.second + dir[1];
                if (0 <= x && x < m && 0 <= y && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }
            q.pop();
        }
        return ans;
    }
};
