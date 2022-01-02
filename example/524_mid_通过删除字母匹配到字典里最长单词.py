# 524. 通过删除字母匹配到字典里最长单词
# 给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

# 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。

 

# 示例 1：

# 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
# 输出："apple"
# 示例 2：

# 输入：s = "abpcplea", dictionary = ["a","b","c"]
# 输出："a"
 

# 提示：

# 1 <= s.length <= 1000
# 1 <= dictionary.length <= 1000
# 1 <= dictionary[i].length <= 1000
# s 和 dictionary[i] 仅由小写英文字母组成
# 通过次数68,270提交次数138,055


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        size = 0
        index = 0
        res = ''

        for di in dictionary:
            m = len(di)
            err = 0
            if m < size:
                continue
            
            elif m == size:
                for i in range(len(di)):
                    if ord(di[i]) > ord(res[i]):
                        err = 1
                        break
                    elif ord(di[i]) < ord(res[i]):
                        break
            if err:
                continue

            idx = 0
            for j in range(len(s)):
                if s[j] == di[idx]:
                    idx += 1
                
                if idx == m: 
                    size = m
                    res = di
                    index = j                  
                    break

        return res
