# 664. 奇怪的打印机
# 有台奇怪的打印机有以下两个特殊要求：

# 打印机每次只能打印由 同一个字符 组成的序列。
# 每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
# 给你一个字符串 s ，你的任务是计算这个打印机打印它需要的最少打印次数。

 
# 示例 1：

# 输入：s = "aaabbb"
# 输出：2
# 解释：首先打印 "aaa" 然后打印 "bbb"。
# 示例 2：

# 输入：s = "aba"
# 输出：2
# 解释：首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
 

# 提示：

# 1 <= s.length <= 100
# s 由小写英文字母组成
# 通过次数15,707提交次数24,830


class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for L in range(n-1, -1, -1):      #L依赖于右侧
            for R in range(L + 1, n):   #R依赖于左侧
                if s[L] == s[R]:
                    dp[L][R] = dp[L][R-1]
                else:
                    tmp = 1000
                    for mid in range(L, R, 1):
                        tmp = min(tmp, dp[L][mid] + dp[mid+1][R])
                    dp[L][R] = tmp
        return dp[0][n-1]
