# 28. 实现 strStr()
# 实现 strStr() 函数。

# 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

 

# 说明：

# 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

# 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

 

# 示例 1：

# 输入：haystack = "hello", needle = "ll"
# 输出：2
# 示例 2：

# 输入：haystack = "aaaaa", needle = "bba"
# 输出：-1
# 示例 3：

# 输入：haystack = "", needle = ""
# 输出：0
 

# 提示：

# 0 <= haystack.length, needle.length <= 5 * 104
# haystack 和 needle 仅由小写英文字符组成
# 通过次数366,385提交次数904,787


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        size = len(needle)
        if size == 0:
            return 0

        same = 0
        i = 0
        while i < len(haystack):
            if needle[same] == haystack[i]:
                same+=1
                if same == size:
                    return i-same+1
            elif same != 0:
                i = i - same
                same = 0
            i += 1

        return -1