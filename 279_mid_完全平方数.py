# 279. 完全平方数
# 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

# 给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

# 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

 

# 示例 1：

# 输入：n = 12
# 输出：3 
# 解释：12 = 4 + 4 + 4
# 示例 2：

# 输入：n = 13
# 输出：2
# 解释：13 = 4 + 9
 
# 提示：

# 1 <= n <= 104
# 通过次数163,542提交次数26


class Solution:
    def numSquares(self, n: int) -> int:
        nums = []
        index = 1
        while index * index <= n:
            nums.append(index * index)
            index += 1

        dp = [n+1] * (n+1)
        dp[0] = 0
        for nu in nums:
            for i in range(1, n+1):
                if i >= nu:
                    dp[i] = min(dp[i], dp[i-nu]+1)

        return dp[-1]

