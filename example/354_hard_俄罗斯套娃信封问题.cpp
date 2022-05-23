// 354. 俄罗斯套娃信封问题
// 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

// 注意：不允许旋转信封。

 
// 示例 1：

// 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
// 输出：3
// 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
// 示例 2：

// 输入：envelopes = [[1,1],[1,1],[1,1]]
// 输出：1
 

// 提示：

// 1 <= envelopes.length <= 105
// envelopes[i].length == 2
// 1 <= wi, hi <= 105
// 通过

// 1 使用动态规划
// 2 维护单增队列
// 3 二分查找单增队列中第一个小于等于的位置

struct cmp {
    bool operator() (const int &a, const int &b) {
        return a < b;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), 
            [](const vector<int> &a, const vector<int> &b){
                if (a[0] == b[0]) {
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            });
        
        int ans = 1;
        vector<int> dp(1, envelopes[0][1]);
        for (int i = 1; i < n; i++) {
            int j = 0;
            
            auto addr = lower_bound(dp.begin(), dp.end(), envelopes[i][1], cmp());

            if (addr == dp.end()) {
                dp.push_back(envelopes[i][1]);
            } else {
                dp[addr - dp.begin()] = envelopes[i][1];
            }
        }

        return dp.size();

    }
};