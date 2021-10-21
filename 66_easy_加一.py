# 66. 加一
# 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

# 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

# 你可以假设除了整数 0 之外，这个整数不会以零开头。

 

# 示例 1：

# 输入：digits = [1,2,3]
# 输出：[1,2,4]
# 解释：输入数组表示数字 123。
# 示例 2：

# 输入：digits = [4,3,2,1]
# 输出：[4,3,2,2]
# 解释：输入数组表示数字 4321。
# 示例 3：

# 输入：digits = [0]
# 输出：[1]
 

# 提示：

# 1 <= digits.length <= 100
# 0 <= digits[i] <= 9
# 通过次数385,553提交次数830,126

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        flag = 0
        size = len(digits)
        digits[size-1] += 1
        for i in range(size-1, -1, -1):
            digits[i] += flag
            flag = 0
            if digits[i] >= 10:
                flag = 1
                digits[i] -= 10
                continue
            else:
                break
        
        if flag:
            digits = [1] + digits

        return digits