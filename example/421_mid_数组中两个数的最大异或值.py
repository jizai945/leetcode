# 421. 数组中两个数的最大异或值
# 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

# 进阶：你可以在 O(n) 的时间解决这个问题吗？

 

# 示例 1：

# 输入：nums = [3,10,5,25,2,8]
# 输出：28
# 解释：最大运算结果是 5 XOR 25 = 28.
# 示例 2：

# 输入：nums = [0]
# 输出：0
# 示例 3：

# 输入：nums = [2,4]
# 输出：6
# 示例 4：

# 输入：nums = [8,10,2]
# 输出：10
# 示例 5：

# 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
# 输出：127
 

# 提示：

# 1 <= nums.length <= 2 * 104
# 0 <= nums[i] <= 231 - 1
# 通过次数21,156提交次数34,731

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # 最高位的二进制位编号为 30
        HIGH_BIT = 30

        x = 0
        for k in range(HIGH_BIT, -1, -1):
            seen = set()
            # 将所有的 pre^k(a_j) 放入哈希表中
            for num in nums:
                # 如果只想保留从最高位开始到第 k 个二进制位为止的部分
                # 只需将其右移 k 位
                seen.add(num >> k)

            # 目前 x 包含从最高位开始到第 k+1 个二进制位为止的部分
            # 我们将 x 的第 k 个二进制位置为 1，即为 x = x*2+1
            x_next = x * 2 + 1
            found = False
            
            # 枚举 i
            for num in nums:
                if x_next ^ (num >> k) in seen:
                    found = True
                    break

            if found:
                x = x_next
            else:
                # 如果没有找到满足等式的 a_i 和 a_j，那么 x 的第 k 个二进制位只能为 0
                # 即为 x = x*2
                x = x_next - 1
        
        return x
