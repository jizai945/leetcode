# 剑指 Offer 38. 字符串的排列
# 输入一个字符串，打印出该字符串中字符的所有排列。

 

# 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

# 示例:

# 输入：s = "abc"
# 输出：["abc","acb","bac","bca","cab","cba"]
 

# 限制：

# 1 <= s 的长度 <= 8

# 通过次数124,076提交次数214,754

class Solution:
    def permutation(self, s: str) -> List[str]:
        ret = set()

        def sub_append(s:str, tmp:str):
            if s == '':
                ret.add(tmp)
                return
            
            for i in range(len(s)):
                tmp += s[i]
                sub_s = s[:i] + s[i+1:]
                sub_append(sub_s, tmp)
                tmp = tmp[:-1]

        
        sub_append(s, '')

        return list(ret)