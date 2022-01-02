# 74. 搜索二维矩阵
# 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

# 每行中的整数从左到右按升序排列。
# 每行的第一个整数大于前一行的最后一个整数。
 

# 示例 1：


# 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
# 输出：true
# 示例 2：


# 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
# 输出：false
 

# 提示：

# m == matrix.length
# n == matrix[i].length
# 1 <= m, n <= 100
# -104 <= matrix[i][j], target <= 104
# 通过次数123,782提交次数281,409
# 在真实的面试中遇到过这道题？



class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0])
        size = row * col
        if size == 0:
            return False
        
        left, right = 0, size-1

        while left <= right:
            mid = (left + right) // 2

            if target == matrix[left//col][left- left//col*col] or\
            target == matrix[right//col][right- right//col*col] or\
            target == matrix[mid//col][mid- mid//col*col]:
                return True

            elif target < matrix[mid//col][mid- mid//col*col]:
                right = mid - 1
            else:
                left = mid + 1

        return False

