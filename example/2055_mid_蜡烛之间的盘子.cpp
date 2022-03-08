// 2055. 蜡烛之间的盘子
// 给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

// 同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

// 比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
// 请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。

 

// 示例 1:

// ex-1

// 输入：s = "**|**|***|", queries = [[2,5],[5,9]]
// 输出：[2,3]
// 解释：
// - queries[0] 有两个盘子在蜡烛之间。
// - queries[1] 有三个盘子在蜡烛之间。
// 示例 2:

// ex-2

// 输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
// 输出：[9,0,0,0,0]
// 解释：
// - queries[0] 有 9 个盘子在蜡烛之间。
// - 另一个查询没有盘子在蜡烛之间。
 

// 提示：

// 3 <= s.length <= 105
// s 只包含字符 '*' 和 '|' 。
// 1 <= queries.length <= 105
// queries[i].length == 2
// 0 <= lefti <= righti < s.length

// 前缀和

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<int> leftArr(m, 0);
        vector<int> rightArr(m, 0);
        
        int leftTmp = 0;
        int leftStep = 0;
        int leftIdx = 0;
        for (int i = 0; i < m; i++) {
            
            if (s[i] == '*') {
                leftTmp++;
            } else {
                leftStep = leftTmp;
                for (int j = leftIdx; j <= i; j++) {
                    rightArr[j] = leftStep;
                }
                leftIdx = i+1;
            }
            leftArr[i] = leftStep;
        }
        for (int j = leftIdx; j < m; j++) {
            rightArr[j] = leftStep;
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int tmp = leftArr[right] - rightArr[left];
            tmp = tmp < 0? 0: tmp;
            ans.emplace_back(tmp);
        }

        return ans;
    }
};
