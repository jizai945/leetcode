# 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [0 for i in range(rowIndex+1)]

        for i in range(0, rowIndex+1):
            for j in range(i, -1, -1):
                if (j == 0 or j == i):
                    res[j] = 1
                else:
                    res[j] = res[j-1]+res[j]

        return res
