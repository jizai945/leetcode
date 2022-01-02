
# 1190. 反转每对括号间的子串
# 给出一个字符串 s（仅含有小写英文字母和括号）。

# 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。

# 注意，您的结果中 不应 包含任何括号。

 

# 示例 1：

# 输入：s = "(abcd)"
# 输出："dcba"
# 示例 2：

# 输入：s = "(u(love)i)"
# 输出："iloveu"
# 示例 3：

# 输入：s = "(ed(et(oc))el)"
# 输出："leetcode"
# 示例 4：

# 输入：s = "a(bcdefghijkl(mno)p)q"
# 输出："apmnolkjihgfedcbq"
 

# 提示：

# 0 <= s.length <= 2000
# s 中只有小写英文字母和括号
# 我们确保所有括号都是成对出现的
# 通过次数31,220提交次数48,506

class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        ret = ""

        for ch in s:
            if ch == '(':
                stack.append('(')
            elif ch ==')':
                tmp = ''
                while stack[-1] != '(':
                    tmp += stack.pop()
                stack.pop()
                if len(stack) == 0:
                    ret += tmp
                else:
                    for t in tmp:
                        stack.append(t)
            elif len(stack) == 0:
                ret += ch
            else:
                stack.append(ch)

        return ret
                    