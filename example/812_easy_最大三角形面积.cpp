// 812. 最大三角形面积
// 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。

// 示例:
// 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// 输出: 2
// 解释: 
// 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。


// 注意:

// 3 <= points.length <= 50.
// 不存在重复的点。
//  -50 <= points[i][j] <= 50.
// 结果误差值在 10^-6 以内都认为是正确答案。


// S=(1/2)*(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)

class Solution {
public:
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0, area;
        int m = points.size();
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                for (int k = j+1; k < m; k++) {
                    area = triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                    ans = max(ans, area);

                }
            }
        }

        return ans;

    }
};