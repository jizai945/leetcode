# 1074. 元素和为目标值的子矩阵数量
# 给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。

# 子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。

# 如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

 

# 示例 1：



# 输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
# 输出：4
# 解释：四个只含 0 的 1x1 子矩阵。
# 示例 2：

# 输入：matrix = [[1,-1],[-1,1]], target = 0
# 输出：5
# 解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
# 示例 3：

# 输入：matrix = [[904]], target = 0
# 输出：0
 

# 提示：

# 1 <= matrix.length <= 100
# 1 <= matrix[0].length <= 100
# -1000 <= matrix[i] <= 1000
# -10^8 <= target <= 10^8

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        def subarraySum(nums: List[int], k: int) -> int:
            mp = Counter([0])
            count = pre = 0
            for x in nums:
                pre += x
                if pre - k in mp:
                    count += mp[pre - k]
                mp[pre] += 1
            return count

        m, n = len(matrix), len(matrix[0])
        ans = 0
        # 枚举上边界
        for i in range(m):
            total = [0] * n
            # 枚举下边界
            for j in range(i, m):
                for c in range(n):
                    # 更新每列的元素和
                    total[c] += matrix[j][c]
                ans += subarraySum(total, target)
        
        return ans
