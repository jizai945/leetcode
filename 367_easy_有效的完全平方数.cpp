// 367. 有效的完全平方数
// 给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

// 进阶：不要 使用任何内置的库函数，如  sqrt 。

 

// 示例 1：

// 输入：num = 16
// 输出：true
// 示例 2：

// 输入：num = 14
// 输出：false
 

// 提示：

// 1 <= num <= 2^31 - 1
// 通过次数113,247提交次数253,455
// 请问您在哪类招聘中遇到此题？


class Solution {
public:
    bool isPerfectSquare(int num) {
        // long long left = 1, right = num;
        int left = 1, right = num;

        while (left <= right) {
            // long long mid = (left + right) / 2 ;
            int mid = (left - right) / 2 + right;
            if (fabs(1.0*num/mid - mid) < 0.01) return true;

            if (1.0*num/mid - mid > 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};