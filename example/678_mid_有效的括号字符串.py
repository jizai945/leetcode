# 678. 有效的括号字符串
# 给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

# 任何左括号 ( 必须有相应的右括号 )。
# 任何右括号 ) 必须有相应的左括号 ( 。
# 左括号 ( 必须在对应的右括号之前 )。
# * 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
# 一个空字符串也被视为有效字符串。
# 示例 1:

# 输入: "()"
# 输出: True
# 示例 2:

# 输入: "(*)"
# 输出: True
# 示例 3:

# 输入: "(*))"
# 输出: True
# 注意:

# 字符串大小将在 [1，100] 范围内。
# 通过次数37,391提交次数98,707


class Solution:
    def checkValidString(self, s: str) -> bool:
        stack = list()
        l = 0

        for ss in s:
            if ss == '(':
                l += 1
                stack.append('(')
            elif ss == ')':
                if l == 0:
                    if len(stack) == 0:
                        return False
                    else:
                        stack = stack[1:]
                else:
                    l -= 1
                    for i in range(len(stack)-1, -1, -1):
                        if stack[i] == '(':
                            stack = stack[:i] + stack[i+1:]
                            break
            else:
                stack.append('*')

        if l == 0:
            return True
        else:
            use = [0]*len(stack)
            for i in range(len(stack)):
                if stack[i] == '(':
                    for j in range(i+1, len(stack)):
                        if use[j] == 0 and stack[j] == '*':
                            use[j] = 1
                            l -= 1
                            break

            return l == 0

                        