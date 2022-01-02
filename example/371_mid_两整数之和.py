# 371. 两整数之和
# 给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

 

# 示例 1：

# 输入：a = 1, b = 2
# 输出：3
# 示例 2：

# 输入：a = 2, b = 3
# 输出：5
 

# 提示：

# -1000 <= a, b <= 1000
# 通过次数77,954提交次数127,520

# 那么问题就容易了，总结一下：

# a + b 的问题拆分为 (a 和 b 的无进位结果) + (a 和 b 的进位结果)
# 无进位加法使用异或运算计算得出
# 进位结果使用与运算和移位运算计算得出
# 循环此过程，直到进位为 0


class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        # 2^32
        MASK = 0x100000000
        # 整型最大值
        MAX_INT = 0x7FFFFFFF
        MIN_INT = MAX_INT + 1
        while b != 0:
            # 计算进位
            carry = (a & b) << 1 
            # 取余范围限制在 [0, 2^32-1] 范围内
            a = (a ^ b) % MASK
            b = carry % MASK
        return a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)   
