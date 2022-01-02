# 583. 两个字符串的删除操作
# 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 

# 示例：

# 输入: "sea", "eat"
# 输出: 2
# 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 

# 提示：

# 给定单词的长度不超过500。
# 给定单词中的字符只含有小写字母。
# 通过次数46,497提交次数75,662

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:

        len1, len2 = len(word1), len(word2)
        dp = [[0 for _ in range(len1+1)] for k in range(len2+1)]

        for i in range(len1+1):
            dp[0][i] = i
        for j in range(len2+1):
            dp[j][0] = j  


        for i in range(1, len1+1):
            for j in range(1, len2+1):
                if word1[i-1] == word2[j-1]:
                    dp[j][i] = dp[j-1][i-1]
                else:
                    dp[j][i] = min(dp[j-1][i], dp[j][i-1]) + 1
        return dp[-1][-1]