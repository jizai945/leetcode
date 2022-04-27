// 417. 太平洋大西洋水流问题
// 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

// 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

// 返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋 。

 

// 示例 1：



// 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// 示例 2：

// 输入: heights = [[2,1],[1,2]]
// 输出: [[0,0],[0,1],[1,0],[1,1]]
 

// 提示：

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105

class Solution {
private:
    int m, n;
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector<vector<int>> state;
public:
    void dfs(vector<vector<int>>& heights, int r, int c, int s) {
        if (r < 0 || c < 0 || r >= m || c >= n) return;
        if ((state[r][c] & s) != 0) return ;

        state[r][c] |= s;
        int rr, cc;
        for (int i = 0; i < 4; i++) {
            rr = r + dir[i][0];
            cc = c + dir[i][1];
            // cout << "====" << rr << " " << cc << endl;
            if (rr < 0 || cc < 0 || rr >= m || cc >= n ||
                heights[rr][cc] >= heights[r][c]) {
                dfs(heights, rr, cc, s);
            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        state = vector(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, 1);
            dfs(heights, i, n-1, 2);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, 0, i, 1);
            dfs(heights, m-1, i, 2);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << i << " " << j << " "  << state[i][j] << endl;
                if (state[i][j] == 3) {
                    vector<int> tmp;
                    tmp.emplace_back(i);
                    tmp.emplace_back(j);
                    ans.emplace_back(tmp);
                }
            }
        }

        return ans;
    }
};

