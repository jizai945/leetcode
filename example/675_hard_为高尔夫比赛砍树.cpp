// 675. 为高尔夫比赛砍树
// 你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：

// 0 表示障碍，无法触碰
// 1 表示地面，可以行走
// 比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
// 每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

// 你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。

// 你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

// 可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

 

// 示例 1：


// 输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
// 输出：6
// 解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。
// 示例 2：


// 输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
// 输出：-1
// 解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
// 示例 3：

// 输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
// 输出：6
// 解释：可以按与示例 1 相同的路径来砍掉所有的树。
// (0,0) 位置的树，可以直接砍去，不用算步数。
 

// 提示：

// m == forest.length
// n == forest[i].length
// 1 <= m, n <= 50
// 0 <= forest[i][j] <= 109

struct Node {
    int high;
    int row, col;
    bool operator< (const Node &b) const {
        return this->high > b.high;
    }
};

struct dirNode {
    int row, col;
    int dis, step;
    bool operator< (const dirNode &b) const {
        if(this->dis != b.dis) {
            return this->dis > b.dis;
        } else {
            return this->step > b.step;
        }
    }
};

class Solution {
private:
    int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};
public:

    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size();
        priority_queue<Node> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] > 1) {
                    q.push((Node){forest[i][j], i, j});
                }
            }
        }

        // while (!q.empty()) {
        //     cout << q.top().row << " " << q.top().col << endl;
        //     q.pop(); 
        // }

        priority_queue<dirNode> dirQ;
        priority_queue<dirNode> empty;
        vector<vector<int>> visit(n, vector<int>(m, 0));
        vector<vector<int>> visitEmpty(n, vector<int>(m, 0));
        dirQ.push((dirNode){0, 0, 0, 0});
        int x, y, step;
        while (!q.empty() && !dirQ.empty()) {
            x = dirQ.top().row;
            y = dirQ.top().col;
            step = dirQ.top().step;
            dirQ.pop();
            // cout << x <<" " << y << " "  << step << endl;
            if (q.top().row == x && q.top().col == y) {
                q.pop();
                dirQ = empty;
                visit = visitEmpty;
                // cout << "array---------" << endl;
            } 

            if (!q.empty()) {
                for (int i = 0; i < 4; i++) {
                    int dx = x + dir[i][0];
                    int dy = y + dir[i][1];
                    if (dx>=0 && dy>=0 && dx<n && dy<m && visit[dx][dy]==0 && forest[dx][dy] > 0) {
                        visit[dx][dy] = 1;
                        dirQ.push((dirNode){dx, dy, 
                                    abs(q.top().row-dx) + abs(q.top().col-dy) + step, step+1}); // 这里加step是关键
                    }
                }
            } else {
                return step;
            }
        }

        // cout << q.size() << " " << q.top().row << q.top().col << " " << dirQ.size() << endl;
        return -1;
    }
};

