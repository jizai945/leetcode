# 224. 基本计算器
# 实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。

 

# 示例 1：

# 输入：s = "1 + 1"
# 输出：2
# 示例 2：

# 输入：s = " 2-1 + 2 "
# 输出：3
# 示例 3：

# 输入：s = "(1+(4+5+2)-3)+(6+8)"
# 输出：23
 

# 提示：

# 1 <= s.length <= 3 * 105
# s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
# s 表示一个有效的表达式

class Solution:
    def calculate(self, s: str) -> int:
        ops = [1]
        sign = 1

        ret = 0
        n = len(s)
        i = 0
        while i < n:
            if s[i] == ' ':
                i += 1
            elif s[i] == '+':
                sign = ops[-1]
                i += 1
            elif s[i] == '-':
                sign = -ops[-1]
                i += 1
            elif s[i] == '(':
                ops.append(sign)
                i += 1
            elif s[i] == ')':
                ops.pop()
                i += 1
            else:
                num = 0
                while i < n and s[i].isdigit():
                    num = num * 10 + ord(s[i]) - ord('0')
                    i += 1
                ret += num * sign
        return ret
