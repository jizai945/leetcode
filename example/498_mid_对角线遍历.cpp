// 498. 对角线遍历
// 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。

 

// 示例 1：


// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,4,7,5,3,6,8,9]
// 示例 2：

// 输入：mat = [[1,2],[3,4]]
// 输出：[1,2,3,4]
 

// 提示：

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105
// 通过次数63,524提交次数125,181

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        stack<int> s;

        for (int i = 0; i < (n+m-1); i++) {
            for (int j = 0; j < n; j++) {
                int x = i-j;
                if (x >= m || x < 0 || j >= n) continue;
                if (i % 2 == 0) {
                    ans.push_back(mat[x][j]);
                } else {
                    s.push(mat[x][j]);
                }
            }

            while (!s.empty()) {
                ans.push_back(s.top());
                s.pop();
            }
        }

        return ans;
    }
};
