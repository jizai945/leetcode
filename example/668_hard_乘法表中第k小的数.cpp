// 668. 乘法表中第k小的数
// 几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？

// 给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。

// 例 1：

// 输入: m = 3, n = 3, k = 5
// 输出: 3
// 解释: 
// 乘法表:
// 1	2	3
// 2	4	6
// 3	6	9

// 第5小的数字是 3 (1, 2, 2, 3, 3).
// 例 2：

// 输入: m = 2, n = 3, k = 6
// 输出: 6
// 解释: 
// 乘法表:
// 1	2	3
// 2	4	6

// 第6小的数字是 6 (1, 2, 2, 3, 4, 6).
// 注意：

// m 和 n 的范围在 [1, 30000] 之间。
// k 的范围在 [1, m * n] 之间。

// 思路，大数据中取数，一般都是二分的方法去猜数
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m*n;

        while (left < right) {
            int mid = left + (right - left)/2;
            // 取一个中间数mid，判断有多少个数小于这个数，从而知道取的这个数是比k小还是大了
            if (count(m, n, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    int count(int m, int n, int mid) {
        int ret = 0;
        for (int i = 1; i <= m; i++) {
            // 第i行中有多少个小于mid的数,  第i行的数都是i的倍数
            ret += min(mid/i, n); 
        }
        return ret;
    }
};
