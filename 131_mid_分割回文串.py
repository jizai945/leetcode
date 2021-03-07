# 131. 分割回文串
# 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

# 回文串 是正着读和反着读都一样的字符串。

 

# 示例 1：

# 输入：s = "aab"
# 输出：[["a","a","b"],["aa","b"]]
# 示例 2：

# 输入：s = "a"
# 输出：[["a"]]
 

# 提示：

# 1 <= s.length <= 16
# s 仅由小写英文字母组成
# 通过次数80,371提交次数111,432


# 自己做的
# class Solution:
#     def check_str(self, s : str, l : int, r : int) -> bool:
#         if l == r:
#             return True
#         while l < r:
#             if s[l] != s[r]:
#                 return False
#             l += 1
#             r += -1
#         return True

#     def partition(self, s: str) -> List[List[str]]:
#         res, sub = [], []   
#         size = len(s)    

#         for i in range(size):
#             if self.check_str( s, 0, i) == True:
#                 if (i+1 < size):
#                     tmp = self.partition( s[i+1 : size] )
#                     for row in range(len(tmp)):
#                         sub = []
#                         sub.append(s[0:i+1])
#                         for col_list in tmp[row]:
#                             sub.append(col_list)
#                         res.append(sub)
#                 else:
#                     res.append([s[0:i+1]])
                        
#             else:
#                 continue

#         return res

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        f = [[True] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = (s[i] == s[j]) and f[i + 1][j - 1]

        ret = list()
        ans = list()

        def dfs(i: int):
            if i == n:
                ret.append(ans[:])
                return
            
            for j in range(i, n):
                if f[i][j]:
                    ans.append(s[i:j+1])
                    dfs(j + 1)
                    ans.pop()

        dfs(0)
        return ret

