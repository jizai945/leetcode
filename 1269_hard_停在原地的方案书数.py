# 1269. 停在原地的方案数
# 有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。

# 每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。

# 给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。

# 由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

 

# 示例 1：

# 输入：steps = 3, arrLen = 2
# 输出：4
# 解释：3 步后，总共有 4 种不同的方法可以停在索引 0 处。
# 向右，向左，不动
# 不动，向右，向左
# 向右，不动，向左
# 不动，不动，不动
# 示例  2：

# 输入：steps = 2, arrLen = 4
# 输出：2
# 解释：2 步后，总共有 2 种不同的方法可以停在索引 0 处。
# 向右，向左
# 不动，不动
# 示例 3：

# 输入：steps = 4, arrLen = 2
# 输出：8
 

# 提示：

# 1 <= steps <= 500
# 1 <= arrLen <= 10^6
# 通过次数22,755提交次数46,825

class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:

        MOD = 10**9+7
        # 如果想要取到steps/2那一位, 需要+1, 但是arrLen不需要+1, 本来 arrLen = 2, 数组下标可以从 0 开始的
        maxLen = min(steps//2+1, arrLen)
        # 不能使用这个来初始化数组! 会导致数组中的子一维数组地址都是一样, 改动一个其他都会改变
        # dp = [[0] * maxLen] * (steps + 1)
        dp = [[0 for _ in range(maxLen)] for _ in range(steps + 1)]

        # 移动0 step 到 0 这个arrLen只有1种途径: 不移动
        dp[0][0] = 1
        # 这里 step 从 1 开始是因为 移动 0 步到任意的arrLen都没有用, 过不去...
        for step in range(1, steps+1):
            for j in range(maxLen):
                # 不移动
                dp[step][j] =  dp[step-1][j] % MOD

                # 从 j-1 那格到 j, 右移一步 
                if j-1>=0:
                    dp[step][j] = (dp[step][j] + dp[step-1][j-1]) % MOD
                # 从j+1 那格到 j, 左移一步
                if j+1 < maxLen:
                    dp[step][j] = (dp[step][j] + dp[step-1][j+1]) % MOD
        # 最终要的结果是在 steps 步, 且回到原点 0的方案数      
        return dp[steps][0]

