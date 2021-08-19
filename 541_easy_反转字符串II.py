# 541. 反转字符串 II
# 给定一个字符串 s 和一个整数 k，从字符串开头算起，每 2k 个字符反转前 k 个字符。

# 如果剩余字符少于 k 个，则将剩余字符全部反转。
# 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

# 示例 1：

# 输入：s = "abcdefg", k = 2
# 输出："bacdfeg"
# 示例 2：

# 输入：s = "abcd", k = 2
# 输出："bacd"
 

# 提示：

# 1 <= s.length <= 104
# s 仅由小写英文组成
# 1 <= k <= 104
# 通过次数45,208提交次数77,331

class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        m = len(s) 

        res = s
        for i in range(0,m,k*2):
            tmp = s[i:i+k]
            tmp = tmp[::-1]
            res = res[0:i] + tmp + res[i+k:]

        return res