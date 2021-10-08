# 187. 重复的DNA序列
# 所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

# 编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

 

# 示例 1：

# 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
# 输出：["AAAAACCCCC","CCCCCAAAAA"]
# 示例 2：

# 输入：s = "AAAAAAAAAAAAA"
# 输出：["AAAAAAAAAA"]
 

# 提示：

# 0 <= s.length <= 105
# s[i] 为 'A'、'C'、'G' 或 'T'
# 通过次数67,577提交次数130,898

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        size = len(s)
        if size <= 10:
            return []

        ret = list()
        map = dict()
        for i in range(size-10+1):
            if s[i:i+10] not in map:
                map[s[i:i+10]] = 1
            elif map[s[i:i+10]] == 1:
                ret.append(s[i:i+10])
                map[s[i:i+10]] += 1

        return ret 
