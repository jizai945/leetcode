# 338. 比特位计数
# 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

# 示例 1:

# 输入: 2
# 输出: [0,1,1]
# 示例 2:

# 输入: 5
# 输出: [0,1,1,2,1,2]
# 进阶:

# 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
# 要求算法的空间复杂度为O(n)。
# 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。


# 核心思路: 1.奇数比前面 那个偶数的1的值多一
#           2. 偶数1的个数和 当前数/2  即右移一位数的  1个数相同
class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0]

        for i in range(1, num+1):
            if i%2:
                res.append(res[i-1]+1)
            else:
                res.append(res[i//2])

        return res