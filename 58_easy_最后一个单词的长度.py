# 58. 最后一个单词的长度
# 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

# 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

 

# 示例 1：

# 输入：s = "Hello World"
# 输出：5
# 示例 2：

# 输入：s = "   fly me   to   the moon  "
# 输出：4
# 示例 3：

# 输入：s = "luffy is still joyboy"
# 输出：6
 

# 提示：

# 1 <= s.length <= 104
# s 仅有英文字母和空格 ' ' 组成
# s 中至少存在一个单词
# 通过次数242,317提交次数651,836

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # s_list = s.split()
        # return len(s_list[-1])

        idx = len(s) - 1
        while s[idx] == ' ':
            idx -= 1

        res = 0
        while s[idx] != ' ' and idx != -1:
            idx -= 1
            res += 1
        return res