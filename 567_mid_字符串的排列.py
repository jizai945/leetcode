# 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

# 换句话说，第一个字符串的排列之一是第二个字符串的子串。

# 示例1:

# 输入: s1 = "ab" s2 = "eidbaooo"
# 输出: True
# 解释: s2 包含 s1 的排列之一 ("ba").


# 示例2:

# 输入: s1= "ab" s2 = "eidboaoo"
# 输出: False


# 注意：

# 输入的字符串只包含小写字母
# 两个字符串的长度都在 [1, 10,000] 之间

# ---------------------------计算窗口中的权重值是否相等
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        size = 0
        for ch in s1:
            size += pow(26, ord(ch)-ord('a'))

        window = 0
        for ch in s2[:len(s1)]:
            window += pow(26, ord(ch)-ord('a'))

        for i in range(0, len(s2)-len(s1)+1):
            if i:
                window -= pow(26, ord(s2[i-1])-ord('a'))
                window += pow(26, ord(s2[i+len(s1)-1])-ord('a'))

            if window == size:
                return True

        return False

# ----------------------------字典

# class Solution:
#     def checkInclusion(self, s1: str, s2: str) -> bool:
#         mydict = {}

#         for ch in s1:
#             if ch not in mydict:
#                 mydict[ch] = 1
#             else:
#                 mydict[ch] += 1

#         for i in range(0, len(s2)-len(s1)+1):
#             if s2[i] not in mydict:
#                 continue
#             else:
#                 copydict = mydict.copy()
#                 for j in range(i, len(s1)+i):
#                     if s2[j] not in copydict or copydict[s2[j]] == 0:
#                         break
#                     else:
#                         copydict[s2[j]] -= 1

#                     if j == len(s1)+i-1:
#                         return True

#         return False
